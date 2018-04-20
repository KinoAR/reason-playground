let promptLine = (message) => {
  print_endline(message);
  read_line();
};

let writeFile = (fileName:string) => {
  let openChannel = open_out(fileName);
  "Enter Message" |> promptLine |>output_string(openChannel);
  close_out(openChannel);
};


let fileWrite = "Enter File Name" |> promptLine |> writeFile;
