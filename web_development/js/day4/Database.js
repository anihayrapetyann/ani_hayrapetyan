class Database {
    static get() {
        if(localStorage.db){
            return localStorage.db;
        }
        localStorage.setItem('db', JSON.stringify([]));
        return localStorage.db;
    }

    createTable(name, [ID, username, password], value = null ) {
        const db = JSON.parse(Database.get());
        for ( let elem in db) {
            if (db[elem].name == name) {
                return;
            }
        }
        db.push({name: name, columns:[ID, username, password], value: value});
        localStorage.setItem('db', JSON.stringify(db));
    }
    getTable(name) {
        const newArray = JSON.parse(localStorage.getItem('db'));
        console.log(newArray.find(el => (el.name == name)));
    }
}
