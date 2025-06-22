class Bird {
public:
    virtual void fly() = 0;
};

class Ostrich : public Bird {
public:
    void fly() override {
        throw std::runtime_error("Ostriches can't fly!");
    }
};

// Ostrich violates LSP because it cannot fly but is forced to implement fly.

class Bird {
public:
    virtual void eat() = 0;
    virtual ~Bird() = default;
};

class FlyingBird : public Bird {
public:
    virtual void fly() = 0;
};
// FlyingBird can fly and eat.

class Sparrow : public FlyingBird {
public:
    void eat() override { /* ... */ }
    void fly() override { /* ... */ }
};
// Sparrow can fly and eat.

class Ostrich : public Bird {
public:
    void eat() override { /* ... */ }
};
// Ostrich can eat.
