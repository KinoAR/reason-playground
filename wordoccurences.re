/* Kino Rose */
/* A program that counts the occurences of words in a file, or rather
the occurence of a string of text in a file */
let args = Array.sub(Sys.argv, 1, Array.length(Sys.argv) - 1);
type wordMap = {.
  def: string => string
};

type occurence = {
  name: string,
  occurence: int
};

let fileText = (fileName) => {
  let lines = ref("");
  let openChannel = open_in(fileName);
  let break = ref(false);
  while(!break^) {
    let result = try(input_line(openChannel)) {
    | End_of_file => ""
    };
    if(String.length(result) < 1) {
      break := true;
    };
    lines := lines^ ++ result ++ " ";
  };
  close_in(openChannel);
  lines^;
};

let trimFileName = (name) => 
  String.contains_from(name, String.length(name), '/') ?
  String.sub(name, 0, String.length(name) - 1) : name;

let getFileInfo = (fileName) => fileName |> trimFileName |> fileText;

let addOccurences = (list, word) => {
  let nameMatch = (el) => el.name == word;
  let result = try(List.find(nameMatch,list)) {
  | Not_found => {name: word, occurence: 0}
  };
  let updateResult = {...result, occurence:result.occurence+1};
  updateResult.occurence > 1 ? 
    List.append(List.filter((el) => result.name != el.name, list), [updateResult]) 
    : List.append(list, [updateResult]);
};
let wordOccurences = (text) => {
  let occurenceList = ref([]);
  let wordList = text |> Str.split_delim(Str.regexp("[ \n\r\x0c\t]+")) 
  |> List.map(String.lowercase_ascii);
  List.iter((word) => {
    occurenceList := addOccurences(occurenceList^, word);
    (); 
  }, wordList);
  occurenceList^;
};

let printListValue = (el:occurence) => 
  print_endline(el.name ++ ": " ++ string_of_int(el.occurence));

Array.map(getFileInfo, args) |> Array.map(wordOccurences) |> Array.map(List.map(printListValue));
