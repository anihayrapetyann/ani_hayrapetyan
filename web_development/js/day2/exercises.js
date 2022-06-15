"use strict"

//---------------------ex.1-------------------

const input = prompt("Enter the text");
function toUppercase(input) {
    const splited = input.split(" ");
    const firstWord = splited[0].toUpperCase();
    splited.shift();
    const rest = splited.join(' ');
    const result = firstWord.concat(' ', rest);
    return result;
}
console.log(toUppercase(input));

//------------------ex.2-------------------

function DivideArray(arr, size) {
    const subArrays = [];
    for (let i = 0; i < arr.length; i += size) {
        subArrays.push(arr.slice(i, i + size))
    }
    return subArrays;
}
console.log(DivideArray([1, 2, 3, 4, 5, 6, 7, 8], 3));

//-----------------ex.3--------------

function sumOfValues(object) {
    let sum = 0;
    for (const [key, value] of Object.entries(object)) {
        if(!isNaN(value)){
            sum+= value;
        }
    }
    return sum;
}

const object = {
    sum:"Hello", 
    b:10, 
    a:"World!", 
    c:20
}
console.log(sumOfValues(object));

//----------- ex.4 -----------

function vowelCount(string) {
    const vowels = 'aeiouAEIOU';
    let vowelsCount = 0;
    for (let i = 0; i < string.length; i++) {
        if (vowels.indexOf(string[i]) !==-1) {
            vowelsCount++;
        }
    }
    return vowelsCount;
}
console.log(vowelCount("Today is the best day of my life"));

//------------ex.5------------

function sum (arr) {
    let posSum = 0;
    let negSum = 0;
    for (const el of arr) {
        if(el > 0){
            posSum+=el;
        }
        else {
            negSum+=el;
        }
    }
    const result = {
        positive: posSum,
        negative: negSum
    }
    return result;
}
console.log (sum([5, -5, 10, 10, -3]));

//------------ex.6------------

const data = [
    { id: 1, name: 'Name one', city: 'Stepanakert'},
    { id: 2, name: 'Name one', city: 'Yerevan' },
    { id: 3, name: 'Name one', city: 'Moscow' },
    { id: 4, name: 'Name one', city: 'Stepanakert' },
    { id: 5, name: 'Name one', city: 'Yerevan' },
];

const arr = [];
function GetUniqueCities (cities) {
    for (let i = 0; i < cities.length; i++) {
        arr.push(cities[i].city);
    }
    const Array = [...new Set(arr)];
    return Array;
}
console.log(GetUniqueCities(data));

//---------------ex.7---------------

function checkStringsAnagram(a, b) {
    let str1 = a.toLowerCase().replace(/[^a-z0-9]/gi, '').split('').sort().join('');
    let str2 = b.toLowerCase().replace(/[^a-z0-9]/gi, '').split('').sort().join('');
    return str1 === str2; 
 }
 console.log(checkStringsAnagram("anna?","Nana"));

