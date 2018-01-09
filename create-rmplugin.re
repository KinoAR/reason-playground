let fmtString = format_of_string({|
  //=============================================================================
  // %s
  //=============================================================================

  /*:
  * @author Kino
  * @plugindesc description
  *
  *
  * @help
  *
  //=============================================================================
  //  Contact Information
  //=============================================================================
  *
  * Contact me via twitter: EISKino, or on the rpg maker forums.
  * Username on forums: Kino.
  *
  * Forum Link: http://forums.rpgmakerweb.com/index.php?/profile/75879-kino/
  * Website Link: http://endlessillusoft.com/
  * Twitter Link: https://twitter.com/EISKino
  * Patreon Link: https://www.patreon.com/EISKino
  *
  * Hope this plugin helps, and enjoy!
  * --Kino
  */

  (function () {
    function setup() {

    }

    setup();
  })();
  |});
let args = Array.sub(Sys.argv, 1, Array.length(Sys.argv) - 1);
let fmt = Printf.sprintf(fmtString, args[0]);

let writePluginFile = (fileName:string) => {
  let writeChannel = open_out(fileName);
  Printf.fprintf(writeChannel, "%s", fmt);
  close_out(writeChannel);
};

for(element in 0 to Array.length(args) - 1) {
  writePluginFile(args[element]);
}
