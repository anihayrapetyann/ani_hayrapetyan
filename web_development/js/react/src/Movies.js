import React from 'react';
import mila from './mila.jpeg'
import spisok from './spisok.jpg'
import pobeg from './pobeg.jpeg'
import forest from './forest.jpg'
import kriminalnoe_chtivo from './kriminalnoe_chtivo.jpeg'
import interstellar from './interstellar.jpg'

function MoviesList (props) {
    console.log(props.value);
    const movies = [{name: "anun", image: mila, description:"В тюрьме для смертников появляется заключенный с божественным даром. Мистическая драма по роману Стивена Кинга"},
                    {name: "Список Шиндлера", image: spisok, description:"История немецкого промышленника, спасшего тысячи жизней во время Холокоста. Драма Стивена Спилберга"},
                    {name: "Побег из Шоушенка", image: pobeg, description:"Бухгалтер Энди Дюфрейн обвинён в убийстве собственной жены и её любовника. Оказавшись в тюрьме под названием Шоушенк, он сталкивается с жестокостью и беззаконием, царящими по обе стороны решётки. Каждый, кто попадает в эти стены, становится их рабом до конца жизни."},
                    {name: "Форрест Гамп", image: forest, description:"Полувековая история США глазами чудака из Алабамы. Абсолютная классика Роберта Земекиса с Томом Хэнксом"},
                    {name: "Криминальное чтиво", image: kriminalnoe_chtivo, description:"Несколько связанных историй из жизни бандитов. Шедевр Квентина Тарантино, который изменил мировое кино"},
                    {name: "Интерстеллар", image: interstellar, description:"Когда засуха, пыльные бури и вымирание растений приводят человечество к продовольственному кризису, коллектив исследователей и учёных отправляется сквозь червоточину (которая предположительно соединяет области пространства-времени через большое расстояние) в путешествие, чтобы превзойти прежние ограничения для космических путешествий человека и найти планету с подходящими для человечества условиями."}
    ];
    if(props.value == movies[0].name) {
        console.log("Movie")
    }
    const filteredList = movies.find((element) =>  element.name == props.value
        // if(props.value == element.name) {
        //     console.log("gtnvec");
        //   return  <div>
        //         <h1>{element.name}</h1>
        //         <img src={element.image}/>
        //         <p>{element.description}</p>
        //     </div>
        // }
    )
    // console.log(filteredList, "======");

    const listMovies = movies.map((movies) =>
        <div>
            <h1>{movies.name}</h1>
            <img src={movies.image}/>
            <p>{movies.description}</p>
        </div>
    );


//     if(filteredList){ return (
//         <div>
//        <h1>{filteredList.name}</h1>
//        <img src={filteredList.image}/>
//        <p>{filteredList.description}</p>
//    </div>)}
//     else {return listMovies;}

    return (
        <>
        {!props.value && listMovies}
        {filteredList && (<div>
            <h1>{filteredList.name}</h1>
            <img src={filteredList.image}/>
            <p>{filteredList.description}</p>
        </div>)}
        </>)
}

export default MoviesList;