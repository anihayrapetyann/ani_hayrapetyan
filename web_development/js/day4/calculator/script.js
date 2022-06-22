function addFunction() {
    let number1 =Number( document.getElementById("element1").value);
    let number2 =Number( document.getElementById("element2").value);
    const result = number1 + number2;
    const container = document.getElementById('section1');
    document.getElementById("result").innerHTML=String(result);
    document.getElementById('operation').innerHTML = "+";
    return (number1 + number2);
}

function subtractFunction() {
    let number1 =Number( document.getElementById("element1").value);
    let number2 =Number( document.getElementById("element2").value);
    const result = number1 - number2;
    const container = document.getElementById('section1');
    document.getElementById("result").innerHTML=String(result);
    document.getElementById('operation').innerHTML = "-";
    return (number1 - number2);
}

function multiplyFunction() {
    let number1 =Number( document.getElementById("element1").value);
    let number2 =Number( document.getElementById("element2").value);
    const result = number1 * number2;
    const container = document.getElementById('section1');
    document.getElementById("result").innerHTML=String(result);
    document.getElementById('operation').innerHTML = "*";
    return (number1 * number2);
}

function devideFunction() {
    document.getElementById('operation').innerHTML = "/";
    let number1 =Number( document.getElementById("element1").value);
    let number2 =Number( document.getElementById("element2").value);
    const result = number1 / number2;
    const container = document.getElementById('section1');
    document.getElementById("result").innerHTML=String(result);
 
    return (number1 / number2);
}

function clearFunction() {
    document.getElementById("element1").value = "";
    document.getElementById("element2").value = "";
    document.getElementById("result").innerHTML = "";
    document.getElementById('operation').innerHTML = "+";
}

document.addEventListener('keydown', function(event){
    if(event.key === "Escape") {
        clearFunction();
    }
});
