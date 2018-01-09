let file = "test.txt";

let readFile = (fileName:string) => {
  let lines = ref("");
  let openChannel = open_in(fileName);
  let break = ref(false);

  while(!break^) {
    let result = try (input_line(openChannel)) {
    | End_of_file => ""
    };
    if(String.length(result) < 1) {
      break := true;
    };
    lines := lines.contents ++ result ++ "\n";
  };
  close_in(openChannel);
  lines.contents;
};

let countLines = (lines:string) => lines |> String.trim |> Str.split(Str.regexp("[ \n\r\x0c\t]+")) |> List.length;
let lineCount = file |> readFile |> countLines;
print_endline("Line Count: " ++ string_of_int(lineCount));