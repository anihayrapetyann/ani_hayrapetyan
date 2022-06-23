let num = Math.floor(Math.random() * 100);
let input = document.querySelector("input");
let result = document.querySelector('#top > p')
let count = document.querySelector('#count');
let helper = document.querySelector('#bottom > p');
let score = document.querySelector('#score');
let button = document.querySelector('button');

let count1 = Number(count.textContent) - 1;
score.textContent = sessionStorage.getItem("score") || "0";
console.log(num);

document.addEventListener("keydown", function(event) {
    if (event.key == "Enter") {
        console.log(event.key)
        if (input.value == num) {
            result.textContent = "You Win";
            helper.textContent = "";
            input.disabled = true;
            // score.textContent = count.textContent;
            sessionStorage.setItem("score", count1 + 1);
            document.unbind("keydown")
        } else if (input.value < num) {
            if (num - input.value > 20) {
                helper.textContent = "Super High";
            } else {
                helper.textContent = "High";
            }
        } else {
            if (input.value - num > 20) {
                helper.textContent = "Super Low";
            } else {
                helper.textContent = "Low";
            }
        } 
        input.value = "";
        if(count1 < 0) {
            result.textContent = "You Lose";
            helper.textContent = "";
            input.disabled = true;
        } else {
            count.textContent = String(count1--);
        }
    }
});

button.addEventListener("click", function() {
    window.location.reload();
} ) 
