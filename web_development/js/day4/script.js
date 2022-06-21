// localStorage.clear();

const obj = new Database;
obj.createTable("user1", [1, "John", "0001"], 4);
obj.createTable("user2", [2, "Kate", "0002"], 5);
obj.createTable("user2", [3, "Kate", "0002"], 5);
console.log(Database.get());
obj.getTable('user1');