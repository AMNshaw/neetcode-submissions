class Document;

class State {
public:
    virtual ~State() {} 
    virtual void handleRequest(Document* doc) = 0;
};

class Draft : public State {
public:
    void handleRequest(Document* doc) override;
};

class Review : public State {
public:
    void handleRequest(Document* doc) override;
};

class Published : public State {
public:
    void handleRequest(Document* doc) override {}
};

class Document {
private:
    State* state;
    bool approved;

public:
    Document() : state(new Draft()), approved(false) {}
    ~Document() { delete state; }

    State* getState() const { return state; }

    void setState(State* newState) { 
        delete state; 
        state = newState; 
    }

    void publish() { state->handleRequest(this); }

    void setApproval(bool approval) { approved = approval; }
    
    bool isApproved() const { return approved; }


};
void Draft::handleRequest(Document* doc) {
    doc->setState(new Review());

};
void Review::handleRequest(Document* doc) {
    if(doc->isApproved()){
        doc->setState(new Published());
    } else {
        doc->setState(new Draft());
    }
}
