template <typename E> class List { // List ADT
private:
    void operator = (const List&) {} // Protect assignment
    List(const List&) {}

public:
    List() {} // default constructor
    virtual ~List() {} // base constructor

    // Clear contents from the list, to make it empty
    virtual void clear() = 0;

    // insert an element at the current location
    // iterm: the elemnt to be insert
    virtual void insert(const E& item) = 0;

    // append an element at the end of th list
    // item: the element to be appended
    virtual void append(const E& item) = 0;

    // remove and return current element.
    // Return: the element that was removed
    virtual E remove() = 0;

    // set the current position to the start of the list
    virtual void moveToStart() = 0;

    
    // set the current position to th end of the list
    virtual void moveToEnd() = 0;

    // move the current position one step left.
    // no change if already at beginning
    virtual void prev() = 0;

    //  move the current position one step right
    //  no change if already at end 
    virtual void next() = 0;

    // return: the number of elements in the list
    virtual int length() const = 0;

    // return: the position of the current element
    virtual int currPos() const = 0;

    // set current position
    // the position to make current
    virtual void moveToPos(int pos) = 0;

    // return: the current element
    virtual const E& getValue() const = 0;
};

