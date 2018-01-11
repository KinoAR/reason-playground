/*
 * Kino Rose - 1/10/2018
 * File Size Calculator
 */
let args = Array.sub(Sys.argv, 1, Array.length(Sys.argv) - 1);

let fileSizeText = (name, size) =>
  print_endline(name ++ ": " ++ string_of_int(size) ++ " bytes");

let fileSize = name => {
  let size = name |> open_in |> in_channel_length;
  fileSizeText(name, size);
  size;
};

let trimFileName = name =>
  String.contains_from(name, String.length(name), '/') ?
    String.sub(name, 0, String.length(name) - 1) : name;

let rec directorySize = name => {
  let size = ref(0);
  let dirContents = Sys.readdir(name);
  for (num in 0 to Array.length(dirContents) - 1) {
    let contentName =
      String.concat(
        "/",
        [name, dirContents[num]]
      ); /* Need to add / for directories on a lower level */
    let isFile = ! Sys.is_directory(contentName);
    size.contents =
      size.contents
      + (isFile ? fileSize(contentName) : directorySize(contentName));
  };
  fileSizeText(name, size^);
  size^;
};

let getSize = name => {
  let size = ref(0);
  let isDir =
    try (Sys.is_directory(name)) {
    | Sys_error("") => false
    };
  size := isDir ? directorySize(name) : fileSize(name); /* Add one more check for the initial directory */
  let result =
    size^
    + (
      name
      |> Sys.readdir
      |> Array.to_list
      |> List.filter(element => ! Sys.is_directory(element))
      |> List.map(el => fileSize(el))
      |> List.fold_left((a, b) => a + b, 0)
    );
  result;
};

for (fileIndex in 0 to Array.length(args) - 1) {
  let fileName = args[fileIndex];
  print_endline(
    "Total Size: "
    ++ string_of_int(getSize(trimFileName(fileName)))
    ++ " bytes"
  );
};