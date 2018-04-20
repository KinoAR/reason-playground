print_string("Enter Item Price: ");

let inputToFloat = () => read_line() |> float_of_string;
let price = inputToFloat();
print_string("Enter State: ");
let state = read_line() |> String.uppercase_ascii;

let salesTax = switch(state) {
| "CT" => 1.0635
| "MI" => 1.06
| "PA" => 1.0634
| "VA" => 1.0563
| "WV" => 1.0629
| "NC" => 1.069
| "GA" => 1.07
| "SC" => 1.0722
| "AL" => 1.091
| "CA" => 1.0825
| "AZ" => 1.0825
| "NV" => 1.0798
| "WA" => 1.0892
| "ND" => 1.0678
| "SD" => 1.0639
| "NE" => 1.0689
| "KS" => 1.0862
| "OK" => 1.0886
| "IA" => 1.068
| "WI" => 1.0542
| "ME" => 1.055
| "LA" => 1.0998
| "MS" => 1.0707
| "DC" => 1.0575
| "MD" => 1.06
| "NJ" => 1.0685
| "RI" => 1.07
| "MA" => 1.0625 
| "NM" => 1.0755
| "IL" => 1.0864
| "IN" => 1.07
| "OH" => 1.0714
| "UT" => 1.0676
| "MT" => 1.0
| "OR" => 1.0
| "DE" => 1.0
| x => 1.0
};
let priceFormat = Printf.sprintf("Total Price: $ %.2f", price *. salesTax);
print_endline(priceFormat);