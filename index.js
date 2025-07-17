const grid = document.querySelector('.grid');

cardArr1 = ['❤️','😊','😶‍🌫️','😶','😍','🍓','🍒','🍌','🍎'];
console.log(cardArr1);

cardArr = [...cardArr1, ...cardArr1].sort(() => Math.random() - 0.5);
console.log(cardArr);

for(let i=0; i<cardArr.length; i++){
    const card = document.createElement('div');
    card.classList.add('card');
    card.setAttribute('data-emoji', cardArr[i]);
    card.value = cardArr[i];
    card.addEventListener('click', flipCard);
    grid.appendChild(card);
}

let firstCard,secondCard;
let count = 0;

function flipCard(){
    this.classList.add('flip');
    this.innerHTML = this.getAttribute('data-emoji');
    if(!firstCard){
        firstCard = this;
    }
    else{
        secondCard = this;
    }
    if(firstCard && secondCard){
        if(firstCard.value == secondCard.value){
            firstCard.removeEventListener('click', flipCard);
            secondCard.removeEventListener('click', flipCard);
            count += 2;
            firstCard = null;
            secondCard = null;
            checkWinner();
            return;
        }
        else{
            setTimeout(() => {
                firstCard.classList.remove('flip');
                secondCard.classList.remove('flip');
            firstCard = null;
            secondCard = null;
            },500);
        }
    }
    return;
}

function checkWinner(){
    if(count === cardArr.length){
        setTimeout(() =>{
            alert("You Won!!");
        },500);
    }
}