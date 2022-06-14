 "use strict"
alert("Available products\n 1.Snickers - 200AMD,\n 2.Coca-Cola - 400AMD,\n 3.Jermuk - 99.9AMD,\n 4.Chocolate - 1200AMD,\n 5.Candy - 350AMD\n")

const snickersPrice = 200;
const cocaColaPrice = 400;
const jermukPrice = 99.9;
const chocolatePrice = 1200;
const candyPrice = 350;

let snickersCount = 0;
let cocaColaCount = 0;
let jermukCount = 0;
let chocolateCount = 0;
let candyCount = 0;

snickersCount = prompt ("Type the count of snickers");
cocaColaCount = prompt ("Type the count of Cola");
jermukCount = prompt ("Type the count of jermuk");
chocolateCount = prompt ("Type the count of chocolate");
candyCount = prompt ("Type the count of candy");

let sum = (snickersCount * snickersPrice)+(cocaColaCount * cocaColaPrice) + (jermukCount * jermukPrice) + (cocaColaCount * chocolatePrice) + (candyCount * candyPrice);
let payment;

if (sum === 0){
    alert ("You did not buy anything");
}
else {
    alert( "Money to pay - " + sum + " AMD");
        payment = prompt ("Enter amount of money to pay");
    if (payment > sum) {
        alert("Your surrender is " + (payment - sum) + " AMD");
    }
    else if (payment < sum) {
        alert ("You have not enough money");
    }
    else if ( isNaN(payment)) {
        alert("You can't do shopping");
    }
}

if (payment > sum) {
    console.log( "Total price: " + sum + " AMD");
    console.log( "Payment: " + payment + " AMD");
    console.log( "Surrender: " + (payment - sum) + " AMD");
    console.log("\nProducts:");
    if (snickersCount > 0){
        console.log ("Snickers - " + snickersCount + " pack " + (snickersPrice * snickersCount)  + " AMD")
    }
    if (cocaColaCount > 0) {
        console.log ("Coca-cola - " + cocaColaCount + " bottle " + (cocaColaCount * cocaColaPrice) + " AMD");
    }
    if(jermukCount > 0) {
        console.log ("Jermuk - " + jermukCount + " bottle " + (jermukPrice * jermukCount) + " AMD")
    }
    if(cocaColaCount > 0) {
        console.log ("Chocolate - " + chocolateCount + " bar " + (chocolateCount * chocolatePrice) + " AMD")
    }
    if(candyCount > 0) {
        console.log ("Candy - " + candyCount + " pack " + (candyCount * candyPrice) + " AMD")
    }
}