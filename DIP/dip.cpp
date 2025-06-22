class MySQLDatabase {
public:
    void connect() { /* ... */ }
};

class Application {
    MySQLDatabase db;
public:
    void start() {
        db.connect();
    }
};
// Application is tightly coupled to MySQLDatabase.


class IDatabase {
public:
    virtual void connect() = 0;
    virtual ~IDatabase() = default;
};

class MySQLDatabase : public IDatabase {
public:
    void connect() override { /* ... */ }
};

class Application {
    IDatabase& db;
public:
    Application(IDatabase& database) : db(database) {}
    void start() {
        db.connect();
    }
};
