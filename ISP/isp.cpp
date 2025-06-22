class IWorker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
};

class Robot : publi IWorker {
public:
    void work() = 0;
    void eat(); // Requires empty definitation, as Robot can't eat.
}

// A Robot implementing IWorker doesn't need eat.


class IWorkable {
public:
    virtual void work() = 0;
};

class IFeedable {
public:
    virtual void eat() = 0;
};

class Human : public IWorkable, public IFeedable {
public:
    void work() override { /* ... */ }
    void eat() override { /* ... */ }
};
// Human can both work and eat.

class Robot : public IWorkable {
public:
    void work() override { /* ... */ }
};
// Robot can work don't eat.
