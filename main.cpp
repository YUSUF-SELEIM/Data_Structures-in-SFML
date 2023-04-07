#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "button.h"
#include"circularQueue.h"
#include"stack.h"
#include"array.h"
#include"circularList.h"
#include"CircularDoubly.h"
#include "deque.h"
#include "doublelinkedlist.h"

using namespace std;
using namespace sf;

int main() {
    SoundBuffer buffer;
    if (!buffer.loadFromFile("/home/yusuf/CLionProjects/DSAPRO/click_sound.wav")) {
        return -1;
    }
    Sound sound;
    sound.setBuffer(buffer);
    Event event;
    Texture startTexture;
    sf::RenderWindow window(sf::VideoMode(600, 600), "A&Y-PROJECT");
    Font arial;
    arial.loadFromFile("D:\\DSAPRO\\arial.ttf");
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    sf::Texture splashTexture;
    if (!splashTexture.loadFromFile("/home/yusuf/CLionProjects/DSAPRO/logo.png")) {
        return EXIT_FAILURE;
    }

    sf::Sprite splashSprite;
    //draw image in the window
    splashSprite.setTexture(splashTexture);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    sf::Text welcomeScreenText;
    welcomeScreenText.setFont(arial);
    welcomeScreenText.setCharacterSize(24);
    welcomeScreenText.setPosition(160.f, window.getSize().y / 4);
    welcomeScreenText.setFont(arial);
    welcomeScreenText.setCharacterSize(30);
    welcomeScreenText.setString(
            "\tWelcome To Our Project\nData Structure and Algorithms\n\t\t\t\tFinal Project\nAbrar Hosny  Yusuf Abdelfattah\n\n\t\t\tSupervised by\n\t\t\tDr.Soha Ahmed\n\t\t\tEng.Haidy Yasser\n\t\t\tEng.Aya Hagazy\n\n\n\t\t\t   2022 - 2023");
    welcomeScreenText.setPosition(90.f, window.getSize().y / 11);

    Text nextScreen;
    nextScreen.setFont(arial);
    nextScreen.setCharacterSize(30);
    nextScreen.setString("Choose a DS");
    nextScreen.setPosition(0, 600);

    Button startButton("Next ->", {120, 40}, 20, Color(178, 190, 181), startTexture, arial);
    startButton.setPosition({233, 500});
    startButton.setTextColor(Color::Black);


    //// creating choices
    Button array("Array", {90, 20}, 15, Color::White, startTexture, arial);
    Button linkedList("Linked List", {90, 20}, 15, Color::White, startTexture, arial);
    Button circularListB("CircularL", {90, 20}, 15, Color::White, startTexture, arial);
    Button doubly("Doubly", {90, 20}, 15, Color::White, startTexture, arial);
    Button doublyCircular("Doubly Circ.", {90, 20}, 15, Color::White, startTexture, arial);

    Button stackT("Stack", {90, 20}, 15, Color::White, startTexture, arial);
    Button queue("Queue", {90, 20}, 15, Color::White, startTexture, arial);
    Button circular("CircularQ", {90, 20}, 15, Color::White, startTexture, arial);
    Button doubleEnded("Double Ended", {90, 20}, 15, Color::White, startTexture, arial);

    /////////making them invisible
    array.setPosition({0, 600});
    linkedList.setPosition({0, 600});
    circularListB.setPosition({0, 600});
    doubly.setPosition({0, 600});
    doublyCircular.setPosition({0, 600});
    stackT.setPosition({0, 600});
    queue.setPosition({0, 600});
    circular.setPosition({0, 600});
    doubleEnded.setPosition({0, 600});
    bool linkedlistMenuIsOpen = false;
    bool queueMenuIsOpen = false;

    /////creating things for the array
    Array *arrayObject = nullptr;
    Button insert("insert", {100, 40}, 15, Color(178, 190, 181), startTexture, arial);
    Button inB("", {100, 40}, 15, Color::White, startTexture, arial);


    //arrayinsertText---------------------------------------
    array.setPosition({0, 600});
    std::string typedString;
    sf::Text typedText;
    typedText.setFillColor(sf::Color::Black);
    typedText.setFont(arial);
    typedText.setPosition(0, 600);
    insert.setTextColor(Color::Black);

//----------------------------------------------------------------------------

    Button size("Enter size", {100, 40}, 15, Color(178, 190, 181), startTexture, arial);
    Button sizeV("", {100, 40}, 15, Color::White, startTexture, arial);


    //arraySizeText ----------------------------------------------------------------------
    std::string sizetypedString;
    sf::Text sizetypedText;
    sizetypedText.setFillColor(sf::Color::Black);
    sizetypedText.setFont(arial);
    sizetypedText.setPosition(0, 600);

    Button sort("sort", {100, 40}, 15, Color(178, 190, 181), startTexture, arial);
    Button sortB("", {200, 20}, 15, Color::White, startTexture, arial);
    Text textOfSort;
    textOfSort.setFillColor(sf::Color::Black);
    textOfSort.setFont(arial);
    textOfSort.setPosition(0, 600);
    textOfSort.setCharacterSize(15);


    Button Delete("Delete", {100, 40}, 15, Color(178, 190, 181), startTexture, arial);
    Button DelB("", {100, 40}, 15, Color::White, startTexture, arial);

//arrayDeleteText -buttons----------------------------------------------------------------------

    std::string DeltypedString;
    sf::Text DeltypedText;
    DeltypedText.setFillColor(sf::Color::Black);
    DeltypedText.setFont(arial);
    DeltypedText.setPosition(0, 600);

    //Enlarge---------------------------------------
    Button Enlarge("Enlarge", {100, 100}, 15, Color(178, 190, 181), startTexture, arial);

    Button Display("Display", {100, 40}, 15, Color(178, 190, 181), startTexture, arial);
    Button DisplayB("", {200, 20}, 15, Color::White, startTexture, arial);
    Text displayText;
    displayText.setFillColor(Color::Black);
    displayText.setFont(arial);
    displayText.setPosition(0, 600);
    displayText.setCharacterSize(15);

    /////////making them invisible
    insert.setPosition({0, 600});
    sort.setPosition({0, 600});
    sortB.setPosition({0, 600});

    Delete.setPosition({0, 600});
    DelB.setPosition({0, 600});
    Enlarge.setPosition({0, 600});
    Display.setPosition({0, 600});
    inB.setPosition({0, 600});
    DisplayB.setPosition({0, 600});
    size.setPosition({0, 600});
    sizeV.setPosition({0, 600});
    ///Creating things for the stack
    //getting a stack object
    stack st;
    //push Operation
    Button pushButton("Push", {120, 40}, 15, Color(178, 190, 181), startTexture, arial);
    Button pushTextBox("", {120, 40}, 15, Color::White, startTexture, arial);


    pushButton.setPosition({0, 600});
    pushButton.setTextColor(Color::Black);

    pushTextBox.setPosition({0, 600});
    Text typedTextStack;
    string typedStringStack;
    typedTextStack.setFillColor(sf::Color::Black);
    typedTextStack.setFont(arial);
    typedTextStack.setPosition(0, 600);

    //display operation
    Button displayButtonStack("Display", {120, 40}, 15, Color(178, 190, 181), startTexture, arial);
    displayButtonStack.setPosition({0, 600});
    displayButtonStack.setTextColor(Color::Black);

    Button displayTextBoxStack("", {200, 20}, 15, Color::White, startTexture, arial);
    displayTextBoxStack.setPosition({0, 600});
    displayTextBoxStack.setTextColor(Color::Black);


    Text displayForStack;
    displayForStack.setFillColor(sf::Color::Black);
    displayForStack.setFont(arial);
    displayForStack.setPosition(0, 600);
    displayForStack.setCharacterSize(15);

    //pop operation
    Button popButton("Pop", {120, 120}, 15, Color(178, 190, 181), startTexture, arial);
    popButton.setPosition({0, 600});
    popButton.setTextColor(Color::Black);

    //peek operation
    Button peekButton("Peek", {120, 40}, 15, Color(178, 190, 181), startTexture, arial);
    peekButton.setPosition({0, 600});
    peekButton.setTextColor(Color::Black);

    Button peekTextBox("", {120, 40}, 15, Color::White, startTexture, arial);
    peekTextBox.setPosition({0, 600});
    peekTextBox.setTextColor(Color::Black);


    Text peekTextForStack;
    peekTextForStack.setFillColor(sf::Color::Black);
    peekTextForStack.setFont(arial);
    peekTextForStack.setPosition(0, 600);
//////creating things for Circular queue
/////creating a circularQueue object
    circularQueue cq;
    Button enqueueButton("Enqueue", {120, 40}, 15, Color(178, 190, 181), startTexture, arial);
    Button enqueueTextBox("", {120, 40}, 15, Color::White, startTexture, arial);


    enqueueButton.setPosition({0, 600});
    enqueueButton.setTextColor(Color::Black);

    enqueueTextBox.setPosition({0, 600});
    Text typedTextEnqueue;
    string typedStringEnqueue;
    typedTextEnqueue.setFillColor(sf::Color::Black);
    typedTextEnqueue.setFont(arial);
    typedTextEnqueue.setPosition(0, 600);

    ///Dequeue
    Button dequeueButton("Dequeue", {120, 120}, 15, Color(178, 190, 181), startTexture, arial);
    dequeueButton.setPosition({0, 600});
    dequeueButton.setTextColor(Color::Black);


    //display
    Button enqueueDisplayButton("Display", {120, 40}, 15, Color(178, 190, 181), startTexture, arial);
    enqueueDisplayButton.setPosition({0, 600});
    enqueueDisplayButton.setTextColor(Color::Black);

    Button enqueueDisplayTextBox("", {200, 20}, 15, Color::White, startTexture, arial);
    enqueueDisplayTextBox.setPosition({0, 600});
    enqueueDisplayTextBox.setTextColor(Color::Black);

    Text displayForCircularQueue;
    displayForCircularQueue.setFillColor(sf::Color::Black);
    displayForCircularQueue.setFont(arial);
    displayForCircularQueue.setPosition(0, 600);
    displayForCircularQueue.setCharacterSize(15);

    /////things of a circular linked list
    ////INSERTION of Circular List
    circularList circularListObject;
    Node *last = NULL;
    Button insertButtonCircularList("Insert", {120, 40}, 15, Color(178, 190, 181), startTexture, arial);
    Button insertTextBoxCircularList("", {120, 40}, 15, Color::White, startTexture, arial);


    insertButtonCircularList.setPosition({0, 600});
    insertButtonCircularList.setTextColor(Color::Black);

    insertTextBoxCircularList.setPosition({0, 600});
    Text typedTextInsertCircularList;
    string typedStringInsertCircularList;
    typedTextInsertCircularList.setFillColor(sf::Color::Black);
    typedTextInsertCircularList.setFont(arial);
    typedTextInsertCircularList.setPosition(0, 600);
    ////DELETE of Circular List
    Button deleteButtonCircularList("Delete", {120, 40}, 15, Color(178, 190, 181), startTexture, arial);
    Button deleteTextBoxCircularList("", {120, 40}, 15, Color::White, startTexture, arial);


    deleteButtonCircularList.setPosition({0, 600});
    deleteButtonCircularList.setTextColor(Color::Black);

    deleteTextBoxCircularList.setPosition({0, 600});
    Text typedTextDeleteCircularList;
    string typedStringDeleteCircularList;
    typedTextDeleteCircularList.setFillColor(sf::Color::Black);
    typedTextDeleteCircularList.setFont(arial);
    typedTextDeleteCircularList.setPosition(0, 600);
    ////DISPLAY of Circular List
    Button displayButtonCircularList("Display", {120, 40}, 15, Color(178, 190, 181), startTexture, arial);
    displayButtonCircularList.setPosition({0, 600});
    displayButtonCircularList.setTextColor(Color::Black);

    Button displayTextBoxCircularList("", {200, 20}, 15, Color::White, startTexture, arial);
    displayTextBoxCircularList.setPosition({0, 600});
    displayTextBoxCircularList.setTextColor(Color::Black);

    Text displayForCircularList;
    displayForCircularList.setFillColor(sf::Color::Black);
    displayForCircularList.setFont(arial);
    displayForCircularList.setPosition(0, 600);
    displayForCircularList.setCharacterSize(15);
/////deque things
    dequeue dq;
    //insert front Operation
    Button insertFrontButton("insert Front", {120, 40}, 15, Color(178, 190, 181), startTexture, arial);
    Button insertFrontTextBox("", {120, 40}, 15, Color::White, startTexture, arial);


    insertFrontTextBox.setTextColor(Color::Black);
    Text fronttypedText;
    string fronttypedString;
    fronttypedText.setFillColor(sf::Color::Black);
    fronttypedText.setFont(arial);


    //insert rear--------------------------------------------------------------------
    Button insertRearButton("insert Rear", {120, 40}, 15, Color(178, 190, 181), startTexture, arial);
    Button insertRearTextBox("", {120, 40}, 15, Color::White, startTexture, arial);

    insertRearTextBox.setTextColor(Color::Black);

    Text reartypedText;
    string reartypedString;
    reartypedText.setFillColor(sf::Color::Black);
    reartypedText.setFont(arial);


    //display operation----------------------------------------------------------------------------------------------------------------
    Button dedisplayButton("Display", {120, 40}, 15, Color(178, 190, 181), startTexture, arial);
    dedisplayButton.setTextColor(Color::Black);

    Button dedisplayTextBox("", {200, 20}, 15, Color::White, startTexture, arial);
    Text displayFordequeue;
    displayFordequeue.setFillColor(sf::Color::Black);
    displayFordequeue.setFont(arial);
    displayFordequeue.setCharacterSize(15);

    //Dequeue operation front
    Button DequeuefrontButton("Dequeue front", {200, 20}, 15, Color(178, 190, 181), startTexture, arial);

    DequeuefrontButton.setTextColor(Color::Black);
    //Dequeue operation rear
    Button DequeuerearButton("Dequeue rear", {200, 20}, 15, Color(178, 190, 181), startTexture, arial);

    DequeuerearButton.setTextColor(Color::Black);

//hiding deque
    insertFrontButton.setPosition({0, 600});
    insertFrontTextBox.setPosition({0, 600});
    fronttypedText.setPosition(0, 600);
    insertRearButton.setPosition({0, 600});
    insertRearTextBox.setPosition({0, 600});
    reartypedText.setPosition(0, 600);
    dedisplayButton.setPosition({0, 600});
    dedisplayTextBox.setPosition({0, 600});
    displayFordequeue.setPosition(0, 600);
    DequeuerearButton.setPosition({0, 600});
    DequeuefrontButton.setPosition({0, 600});
    //////Circular Doubly List
    //////insert_begin  Operation
    circulardoublylist cd;
    Button insertBeginButtonCircularDoubly("Insert_Begin", {120, 40}, 15, Color(178, 190, 181), startTexture, arial);
    Button insertBeginTextBoxCircularDoubly("", {120, 40}, 15, Color::White, startTexture, arial);
    insertBeginTextBoxCircularDoubly.setTextColor(Color::Black);
    Text insertBeginCircularDoublytypedText;
    string insertBeginCircularDoublytypedString;
    insertBeginCircularDoublytypedText.setFillColor(sf::Color::Black);
    insertBeginCircularDoublytypedText.setFont(arial);
    /////insert_end Operation
    Button insertEndButtonCircularDoubly("Insert_End", {120, 40}, 15, Color(178, 190, 181), startTexture, arial);
    Button insertEndTextBoxCircularDoubly("", {120, 40}, 15, Color::White, startTexture, arial);
    insertEndTextBoxCircularDoubly.setTextColor(Color::Black);
    Text insertEndCircularDoublytypedText;
    string insertEndCircularDoublytypedString;
    insertEndCircularDoublytypedText.setFillColor(sf::Color::Black);
    insertEndCircularDoublytypedText.setFont(arial);
    ////DELETE of Circular Doubly List
    Button deleteButtonCircularDoublyList("Delete", {120, 40}, 15, Color(178, 190, 181), startTexture, arial);
    Button deleteTextBoxCircularDoublyList("", {120, 40}, 15, Color::White, startTexture, arial);
    deleteTextBoxCircularDoublyList.setTextColor(Color::Black);
    Text deleteCircularDoublytypedText;
    string deleteCircularDoublytypedString;
    deleteCircularDoublytypedText.setFillColor(sf::Color::Black);
    deleteCircularDoublytypedText.setFont(arial);
    ////DISPLAY of Circular List
    Button displayButtonCircularDoublyList("Display", {120, 40}, 15, Color(178, 190, 181), startTexture, arial);
    displayButtonCircularDoublyList.setTextColor(Color::Black);
    Button displayTextBoxCircularDoublyList("", {200, 20}, 15, Color::White, startTexture, arial);
    displayTextBoxCircularDoublyList.setTextColor(Color::Black);

    Text displayForCircularDoublyList;
    displayForCircularDoublyList.setFillColor(sf::Color::Black);
    displayForCircularDoublyList.setFont(arial);
    displayForCircularDoublyList.setPosition(0, 600);
    displayForCircularDoublyList.setCharacterSize(15);
    ////circular doubly search
    Button searchButtonCircularDoublyList("Search", {120, 40}, 15, Color(178, 190, 181), startTexture, arial);
    searchButtonCircularDoublyList.setTextColor(Color::Black);
    Button searchTextBoxCircularDoublyList("", {120, 40}, 15, Color::White, startTexture, arial);
    searchTextBoxCircularDoublyList.setTextColor(Color::Black);

    Text searchForCircularDoublyList;
    searchForCircularDoublyList.setFillColor(sf::Color::Black);
    searchForCircularDoublyList.setFont(arial);
    searchForCircularDoublyList.setPosition(0, 600);
    string showSearch;
    /////hiding the things of the Circular doubly list
    insertBeginButtonCircularDoubly.setPosition({0, 600});
    insertBeginTextBoxCircularDoubly.setPosition({0, 600});
    insertBeginCircularDoublytypedText.setPosition(0, 600);
    insertEndButtonCircularDoubly.setPosition({0, 600});
    insertEndTextBoxCircularDoubly.setPosition({0, 600});
    insertEndCircularDoublytypedText.setPosition(0, 600);
    deleteButtonCircularDoublyList.setPosition({0, 600});
    deleteTextBoxCircularDoublyList.setPosition({0, 600});
    deleteCircularDoublytypedText.setPosition(0, 600);
    displayButtonCircularDoublyList.setPosition({0, 600});
    displayTextBoxCircularDoublyList.setPosition({0, 600});
    displayForCircularDoublyList.setPosition(0, 600);
    searchButtonCircularDoublyList.setPosition({0, 600});
    searchTextBoxCircularDoublyList.setPosition({0, 600});
    searchForCircularDoublyList.setPosition(0, 600);
////doubly list
    doublelinkedlist dl;

    //insert front Operation
    Button insertFrontButtondl("insert from Front", {120, 40}, 15, Color(178, 190, 181), startTexture, arial);
    Button insertFrontTextBoxdl("", {120, 40}, 15, Color::White, startTexture, arial);

    insertFrontTextBoxdl.setTextColor(Color::Black);


    Text fronttypedTextdl;
    string fronttypedStringdl;
    fronttypedTextdl.setFillColor(sf::Color::Black);
    fronttypedTextdl.setFont(arial);


    //insert
    Button inserttailButtondl("insert from tail", {120, 40}, 15, Color(178, 190, 181), startTexture, arial);
    Button inserttailTextBoxdl("", {120, 40}, 15, Color::White, startTexture, arial);

    inserttailTextBoxdl.setTextColor(Color::Black);

    Text tailtypedTextdl;
    string tailtypedStringdl;
    tailtypedTextdl.setFillColor(sf::Color::Black);
    tailtypedTextdl.setFont(arial);


    //display operation----------------------------------------------------------------------------------------------------------------
    Button displayButtondl("Display", {120, 40}, 15, Color(178, 190, 181), startTexture, arial);

    displayButtondl.setTextColor(Color::Black);

    Button displayTextBoxdl("", {200, 20}, 15, Color::White, startTexture, arial);

    displayTextBoxdl.setTextColor(Color::Black);
    Text displayFordl;
    displayFordl.setFillColor(sf::Color::Black);
    displayFordl.setFont(arial);

    displayFordl.setCharacterSize(15);




    //Delete operation front
    Button DeletefrontButtondl("Delete from front", {200, 20}, 15, Color(178, 190, 181), startTexture, arial);

    DeletefrontButtondl.setTextColor(Color::Black);
    //Delete operation rear
    Button DeleterearButtondl("Delete from  rear", {200, 20}, 15, Color(178, 190, 181), startTexture, arial);

    DeleterearButtondl.setTextColor(Color::Black);
    //clearing the things of the DL
    insertFrontButtondl.setPosition({0, 600});
    displayFordl.setPosition(0, 600);
    displayTextBoxdl.setPosition({0, 600});
    displayButtondl.setPosition({0, 600});
    tailtypedTextdl.setPosition(0, 600);

    inserttailTextBoxdl.setPosition({0, 600});
    inserttailButtondl.setPosition({0, 600});
    insertFrontTextBoxdl.setPosition({0, 600});
    fronttypedTextdl.setPosition(0, 600);
    DeleterearButtondl.setPosition({0, 600});
    DeletefrontButtondl.setPosition({0, 600});
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    while (window.isOpen()) {

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            } else if (event.type == event.MouseButtonPressed) {
                if (startButton.isMouseOver(window)) {
                    welcomeScreenText.setPosition(0, 600); // make it disappear
                    startButton.setPosition({0, 600});
                    //show choices of dsa
                    sound.play();
                    nextScreen.setPosition(200, 200);
                    array.setPosition({1, 1});
                    linkedList.setPosition({94, 1});
                    stackT.setPosition({187, 1});
                    queue.setPosition({280, 1});
                } else if (linkedList.isMouseOver(window) and !linkedlistMenuIsOpen) {
                    sound.play();
                    circularListB.setPosition({94, 24});
                    doubly.setPosition({94, 47});
                    doublyCircular.setPosition({94, 70});
                    linkedlistMenuIsOpen = true;
                } else if (linkedList.isMouseOver(window) and linkedlistMenuIsOpen) {
                    sound.play();
                    circularListB.setPosition({0, 600});
                    doubly.setPosition({0, 600});
                    doublyCircular.setPosition({0, 600});
                    linkedlistMenuIsOpen = false;
                } else if (queue.isMouseOver(window) and !queueMenuIsOpen) {
                    sound.play();
                    circular.setPosition({280, 24});
                    doubleEnded.setPosition({280, 47});
                    queueMenuIsOpen = true;
                } else if (queue.isMouseOver(window) and queueMenuIsOpen) {
                    sound.play();
                    circular.setPosition({0, 600});
                    doubleEnded.setPosition({0, 600});
                    queueMenuIsOpen = false;
                } else if (stackT.isMouseOver(window)) {
                    sound.play();
                    nextScreen.setPosition(0, 600);
                    /////clearing//////////////
                    //array
                    typedText.setPosition(0, 600);
                    textOfSort.setPosition(0, 600);
                    sizetypedText.setPosition(0, 600);
                    DeltypedText.setPosition(0, 600);
                    insert.setPosition({0, 600});
                    sort.setPosition({0, 600});
                    sortB.setPosition({0, 600});
                    Delete.setPosition({0, 600});
                    DelB.setPosition({0, 600});
                    Enlarge.setPosition({0, 600});
                    Display.setPosition({0, 600});
                    inB.setPosition({0, 600});
                    DisplayB.setPosition({0, 600});
                    size.setPosition({0, 600});
                    sizeV.setPosition({0, 600});
                    ////CIRCULAR QUEUEUE
                    enqueueButton.setPosition({0, 600});
                    enqueueTextBox.setPosition({0, 600});
                    typedTextEnqueue.setPosition(0, 600);
                    dequeueButton.setPosition({0, 600});
                    enqueueDisplayButton.setPosition({0, 600});
                    enqueueDisplayTextBox.setPosition({0, 600});
                    displayForCircularQueue.setPosition(0, 600);
                    ////CIRCULAR LIST
                    insertButtonCircularList.setPosition({0, 600});
                    insertTextBoxCircularList.setPosition({0, 600});
                    typedTextInsertCircularList.setPosition(0, 600);
                    deleteButtonCircularList.setPosition({0, 600});
                    deleteTextBoxCircularList.setPosition({0, 600});
                    typedTextDeleteCircularList.setPosition(0, 600);
                    displayButtonCircularList.setPosition({0, 600});
                    displayTextBoxCircularList.setPosition({0, 600});
                    displayForCircularList.setPosition(0, 600);
                    //deque
                    insertFrontButton.setPosition({0, 600});
                    insertFrontTextBox.setPosition({0, 600});
                    fronttypedText.setPosition(0, 600);
                    insertRearButton.setPosition({0, 600});
                    insertRearTextBox.setPosition({0, 600});
                    reartypedText.setPosition(0, 600);
                    dedisplayButton.setPosition({0, 600});
                    dedisplayTextBox.setPosition({0, 600});
                    displayFordequeue.setPosition(0, 600);
                    DequeuerearButton.setPosition({0, 600});
                    DequeuefrontButton.setPosition({0, 600});
                    /////hiding the things of the Circular doubly list
                    insertBeginButtonCircularDoubly.setPosition({0, 600});
                    insertBeginTextBoxCircularDoubly.setPosition({0, 600});
                    insertBeginCircularDoublytypedText.setPosition(0, 600);
                    insertEndButtonCircularDoubly.setPosition({0, 600});
                    insertEndTextBoxCircularDoubly.setPosition({0, 600});
                    insertEndCircularDoublytypedText.setPosition(0, 600);
                    deleteButtonCircularDoublyList.setPosition({0, 600});
                    deleteTextBoxCircularDoublyList.setPosition({0, 600});
                    deleteCircularDoublytypedText.setPosition(0, 600);
                    displayButtonCircularDoublyList.setPosition({0, 600});
                    displayTextBoxCircularDoublyList.setPosition({0, 600});
                    displayForCircularDoublyList.setPosition(0, 600);
                    searchButtonCircularDoublyList.setPosition({0, 600});
                    searchTextBoxCircularDoublyList.setPosition({0, 600});
                    searchForCircularDoublyList.setPosition(0, 600);
                    //clearing the things of the DL
                    insertFrontButtondl.setPosition({0, 600});
                    displayFordl.setPosition(0, 600);
                    displayTextBoxdl.setPosition({0, 600});
                    displayButtondl.setPosition({0, 600});
                    tailtypedTextdl.setPosition(0, 600);

                    inserttailTextBoxdl.setPosition({0, 600});
                    inserttailButtondl.setPosition({0, 600});
                    insertFrontTextBoxdl.setPosition({0, 600});
                    fronttypedTextdl.setPosition(0, 600);
                    DeleterearButtondl.setPosition({0, 600});
                    DeletefrontButtondl.setPosition({0, 600});
                    /////////////////////////////////////////////////
                    //showing the push things
                    pushTextBox.setPosition({60, 100});
                    typedTextStack.setPosition(60, 100);
                    pushButton.setPosition({60, 160});
                    //showing the display things
                    displayButtonStack.setPosition({395.5, 160});
                    displayTextBoxStack.setPosition({350, 110});
                    displayForStack.setPosition(350, 110);
                    //i had to put these things here cause the border was visible when they were at 0 600
                    displayTextBoxStack.setOutThick(5);
                    displayTextBoxStack.setOutColor(Color::Cyan);
                    //showing pop things
                    popButton.setPosition({60, 360});
                    //showing peek things
                    peekButton.setPosition({395.5, 435});
                    peekTextBox.setPosition({395.5, 375});
                    peekTextForStack.setPosition(395.5, 375);
                    peekTextBox.setOutThick(5);
                    peekTextBox.setOutColor(Color::Cyan);
                } else if (pushButton.isMouseOver(window) and !typedStringStack.empty()) {
                    sound.play();
                    st.push(stoi(typedStringStack));
                    typedStringStack = "";
                    typedTextStack.setString("");
                } else if (displayButtonStack.isMouseOver(window)) {
                    sound.play();
                    displayForStack.setString(st.display());
                } else if (popButton.isMouseOver(window)) {
                    sound.play();
                    st.pop();
                } else if (peekButton.isMouseOver(window)) {
                    sound.play();
                    peekTextForStack.setString(st.peek());
                } else if (circular.isMouseOver(window)) {
                    sound.play();
                    nextScreen.setPosition(0, 600);
                    /////clearing///////////////
                    //array
                    typedText.setPosition(0, 600);
                    textOfSort.setPosition(0, 600);
                    sizetypedText.setPosition(0, 600);
                    DeltypedText.setPosition(0, 600);
                    insert.setPosition({0, 600});
                    sort.setPosition({0, 600});
                    sortB.setPosition({0, 600});
                    Delete.setPosition({0, 600});
                    DelB.setPosition({0, 600});
                    Enlarge.setPosition({0, 600});
                    Display.setPosition({0, 600});
                    inB.setPosition({0, 600});
                    DisplayB.setPosition({0, 600});
                    size.setPosition({0, 600});
                    sizeV.setPosition({0, 600});
                    /////STACK
                    pushButton.setPosition({0, 600});
                    pushTextBox.setPosition({0, 600});
                    typedTextStack.setPosition(0, 600);
                    displayButtonStack.setPosition({0, 600});
                    displayTextBoxStack.setPosition({0, 600});
                    displayForStack.setPosition(0, 600);
                    popButton.setPosition({0, 600});
                    peekButton.setPosition({0, 600});
                    peekTextBox.setPosition({0, 600});
                    peekTextForStack.setPosition(0, 600);
                    ////CIRCULAR LIST
                    insertButtonCircularList.setPosition({0, 600});
                    insertTextBoxCircularList.setPosition({0, 600});
                    typedTextInsertCircularList.setPosition(0, 600);
                    deleteButtonCircularList.setPosition({0, 600});
                    deleteTextBoxCircularList.setPosition({0, 600});
                    typedTextDeleteCircularList.setPosition(0, 600);
                    displayButtonCircularList.setPosition({0, 600});
                    displayTextBoxCircularList.setPosition({0, 600});
                    displayForCircularList.setPosition(0, 600);
                    //deque
                    insertFrontButton.setPosition({0, 600});
                    insertFrontTextBox.setPosition({0, 600});
                    fronttypedText.setPosition(0, 600);
                    insertRearButton.setPosition({0, 600});
                    insertRearTextBox.setPosition({0, 600});
                    reartypedText.setPosition(0, 600);
                    dedisplayButton.setPosition({0, 600});
                    dedisplayTextBox.setPosition({0, 600});
                    displayFordequeue.setPosition(0, 600);
                    DequeuerearButton.setPosition({0, 600});
                    DequeuefrontButton.setPosition({0, 600});
                    /////hiding the things of the Circular doubly list
                    insertBeginButtonCircularDoubly.setPosition({0, 600});
                    insertBeginTextBoxCircularDoubly.setPosition({0, 600});
                    insertBeginCircularDoublytypedText.setPosition(0, 600);
                    insertEndButtonCircularDoubly.setPosition({0, 600});
                    insertEndTextBoxCircularDoubly.setPosition({0, 600});
                    insertEndCircularDoublytypedText.setPosition(0, 600);
                    deleteButtonCircularDoublyList.setPosition({0, 600});
                    deleteTextBoxCircularDoublyList.setPosition({0, 600});
                    deleteCircularDoublytypedText.setPosition(0, 600);
                    displayButtonCircularDoublyList.setPosition({0, 600});
                    displayTextBoxCircularDoublyList.setPosition({0, 600});
                    displayForCircularDoublyList.setPosition(0, 600);
                    searchButtonCircularDoublyList.setPosition({0, 600});
                    searchTextBoxCircularDoublyList.setPosition({0, 600});
                    searchForCircularDoublyList.setPosition(0, 600);
                    //clearing the things of the DL
                    insertFrontButtondl.setPosition({0, 600});
                    displayFordl.setPosition(0, 600);
                    displayTextBoxdl.setPosition({0, 600});
                    displayButtondl.setPosition({0, 600});
                    tailtypedTextdl.setPosition(0, 600);

                    inserttailTextBoxdl.setPosition({0, 600});
                    inserttailButtondl.setPosition({0, 600});
                    insertFrontTextBoxdl.setPosition({0, 600});
                    fronttypedTextdl.setPosition(0, 600);
                    DeleterearButtondl.setPosition({0, 600});
                    DeletefrontButtondl.setPosition({0, 600});
                    /////////////////////////////////////////////////
                    //enqueue
                    enqueueTextBox.setPosition({60, 100});
                    typedTextEnqueue.setPosition(60, 100);
                    enqueueButton.setPosition({60, 160});
                    //dequeue
                    dequeueButton.setPosition({60, 360});
                    //showing the display things
                    enqueueDisplayButton.setPosition({395.5, 160});
                    enqueueDisplayTextBox.setPosition({350, 110});
                    displayForCircularQueue.setPosition(350, 110);
                    //i had to put these things here cause the border was visible when they were at 0 600
                    enqueueDisplayTextBox.setOutThick(5);
                    enqueueDisplayTextBox.setOutColor(Color::Cyan);
                } else if (enqueueButton.isMouseOver(window) and !typedStringEnqueue.empty()) {
                    sound.play();
                    cq.enQueue(stoi(typedStringEnqueue));
                    typedStringEnqueue = "";
                    typedTextEnqueue.setString("");
                } else if (enqueueDisplayButton.isMouseOver(window)) {
                    sound.play();
                    displayForCircularQueue.setString(cq.display());
                } else if (dequeueButton.isMouseOver(window)) {
                    sound.play();
                    cq.deQueue();
                } else if (array.isMouseOver(window)) {
                    sound.play();
                    nextScreen.setPosition(0, 600);
                    /////clearing///////////////
                    /////STACK
                    pushButton.setPosition({0, 600});
                    pushTextBox.setPosition({0, 600});
                    typedTextStack.setPosition(0, 600);
                    displayButtonStack.setPosition({0, 600});
                    displayTextBoxStack.setPosition({0, 600});
                    displayForStack.setPosition(0, 600);
                    popButton.setPosition({0, 600});
                    peekButton.setPosition({0, 600});
                    peekTextBox.setPosition({0, 600});
                    peekTextForStack.setPosition(0, 600);
                    ////CIRCULAR QUEUEUE
                    enqueueButton.setPosition({0, 600});
                    enqueueTextBox.setPosition({0, 600});
                    typedTextEnqueue.setPosition(0, 600);
                    dequeueButton.setPosition({0, 600});
                    enqueueDisplayButton.setPosition({0, 600});
                    enqueueDisplayTextBox.setPosition({0, 600});
                    displayForCircularQueue.setPosition(0, 600);
                    ////CIRCULAR LIST
                    insertButtonCircularList.setPosition({0, 600});
                    insertTextBoxCircularList.setPosition({0, 600});
                    typedTextInsertCircularList.setPosition(0, 600);
                    deleteButtonCircularList.setPosition({0, 600});
                    deleteTextBoxCircularList.setPosition({0, 600});
                    typedTextDeleteCircularList.setPosition(0, 600);
                    displayButtonCircularList.setPosition({0, 600});
                    displayTextBoxCircularList.setPosition({0, 600});
                    displayForCircularList.setPosition(0, 600);
                    //deque
                    insertFrontButton.setPosition({0, 600});
                    insertFrontTextBox.setPosition({0, 600});
                    fronttypedText.setPosition(0, 600);
                    insertRearButton.setPosition({0, 600});
                    insertRearTextBox.setPosition({0, 600});
                    reartypedText.setPosition(0, 600);
                    dedisplayButton.setPosition({0, 600});
                    dedisplayTextBox.setPosition({0, 600});
                    displayFordequeue.setPosition(0, 600);
                    DequeuerearButton.setPosition({0, 600});
                    DequeuefrontButton.setPosition({0, 600});
                    /////hiding the things of the Circular doubly list
                    insertBeginButtonCircularDoubly.setPosition({0, 600});
                    insertBeginTextBoxCircularDoubly.setPosition({0, 600});
                    insertBeginCircularDoublytypedText.setPosition(0, 600);
                    insertEndButtonCircularDoubly.setPosition({0, 600});
                    insertEndTextBoxCircularDoubly.setPosition({0, 600});
                    insertEndCircularDoublytypedText.setPosition(0, 600);
                    deleteButtonCircularDoublyList.setPosition({0, 600});
                    deleteTextBoxCircularDoublyList.setPosition({0, 600});
                    deleteCircularDoublytypedText.setPosition(0, 600);
                    displayButtonCircularDoublyList.setPosition({0, 600});
                    displayTextBoxCircularDoublyList.setPosition({0, 600});
                    displayForCircularDoublyList.setPosition(0, 600);
                    searchButtonCircularDoublyList.setPosition({0, 600});
                    searchTextBoxCircularDoublyList.setPosition({0, 600});
                    searchForCircularDoublyList.setPosition(0, 600);
                    //clearing the things of the DL
                    insertFrontButtondl.setPosition({0, 600});
                    displayFordl.setPosition(0, 600);
                    displayTextBoxdl.setPosition({0, 600});
                    displayButtondl.setPosition({0, 600});
                    tailtypedTextdl.setPosition(0, 600);

                    inserttailTextBoxdl.setPosition({0, 600});
                    inserttailButtondl.setPosition({0, 600});
                    insertFrontTextBoxdl.setPosition({0, 600});
                    fronttypedTextdl.setPosition(0, 600);
                    DeleterearButtondl.setPosition({0, 600});
                    DeletefrontButtondl.setPosition({0, 600});
                    ///////////////////////////////////////////
                    size.setPosition({60, 160});
                    sizeV.setPosition({60, 100});
                    sizetypedText.setPosition({60, 100});
                    /////////////////////////////////////////////////
                    insert.setPosition({400, 160});
                    inB.setPosition({400, 100});
                    typedText.setPosition({400, 100});
                    ///////////////////////////////////////////////////////
                    sort.setPosition({400, 300});
                    sortB.setPosition({350, 250});
                    textOfSort.setPosition({350, 250});
                    sortB.setOutThick(2);
                    sortB.setOutColor(Color::Cyan);
                    //////////////////////////////////////////////////////
                    Delete.setPosition({60, 500});
                    DelB.setPosition({60, 440});
                    DeltypedText.setPosition({60, 440});
                    /////////////////////////////
                    Enlarge.setPosition({400, 440});
                    ////////////////////////////////////////////////
                    Display.setPosition({60, 300});
                    DisplayB.setPosition({10, 250});
                    displayText.setPosition(10, 250);
                    DisplayB.setOutThick(2);
                    DisplayB.setOutColor(Color::Cyan);
                } else if (insert.isMouseOver(window) and !typedString.empty() and arrayObject != nullptr) {
                    sound.play();
                    arrayObject->Fill(typedString);
                    typedString = "";
                    typedText.setString("");
                    //delete------------------------------
                } else if (Delete.isMouseOver(window) and !DeltypedString.empty() and arrayObject != nullptr) {
                    sound.play();
                    arrayObject->delet(DeltypedString);
                    DeltypedString = "";
                    DeltypedText.setString("");
                    //Enlarge----------------------------------------
                } else if (Enlarge.isMouseOver(window) and arrayObject != nullptr) {
                    sound.play();
                    arrayObject->Enlarge();
                    //size-------------------------------------------------------------
                } else if (size.isMouseOver(window) and !sizetypedString.empty()) {
                    sound.play();
                    arrayObject = new Array(stoi(sizetypedString));
                    sizetypedString = "";
                    sizetypedText.setString("");
                    //Display --------------------------------------------------------
                } else if (Display.isMouseOver(window) and arrayObject != nullptr) {
                    sound.play();
                    displayText.setString(arrayObject->display());
                    //sort------------------------------
                } else if (sort.isMouseOver(window) and arrayObject != nullptr) {
                    sound.play();
                    textOfSort.setString(arrayObject->sort());
                } else if (circularListB.isMouseOver(window)) {
                    sound.play();
                    nextScreen.setPosition(0, 600);
                    /////clearing///////////////
                    //array
                    typedText.setPosition(0, 600);
                    textOfSort.setPosition(0, 600);
                    sizetypedText.setPosition(0, 600);
                    DeltypedText.setPosition(0, 600);
                    insert.setPosition({0, 600});
                    sort.setPosition({0, 600});
                    sortB.setPosition({0, 600});
                    Delete.setPosition({0, 600});
                    DelB.setPosition({0, 600});
                    Enlarge.setPosition({0, 600});
                    Display.setPosition({0, 600});
                    inB.setPosition({0, 600});
                    DisplayB.setPosition({0, 600});
                    size.setPosition({0, 600});
                    sizeV.setPosition({0, 600});
                    /////STACK
                    pushButton.setPosition({0, 600});
                    pushTextBox.setPosition({0, 600});
                    typedTextStack.setPosition(0, 600);
                    displayButtonStack.setPosition({0, 600});
                    displayTextBoxStack.setPosition({0, 600});
                    displayForStack.setPosition(0, 600);
                    popButton.setPosition({0, 600});
                    peekButton.setPosition({0, 600});
                    peekTextBox.setPosition({0, 600});
                    peekTextForStack.setPosition(0, 600);
                    ////CIRCULAR QUEUEUE
                    enqueueButton.setPosition({0, 600});
                    enqueueTextBox.setPosition({0, 600});
                    typedTextEnqueue.setPosition(0, 600);
                    dequeueButton.setPosition({0, 600});
                    enqueueDisplayButton.setPosition({0, 600});
                    enqueueDisplayTextBox.setPosition({0, 600});
                    displayForCircularQueue.setPosition(0, 600);
                    //deque
                    insertFrontButton.setPosition({0, 600});
                    insertFrontTextBox.setPosition({0, 600});
                    fronttypedText.setPosition(0, 600);
                    insertRearButton.setPosition({0, 600});
                    insertRearTextBox.setPosition({0, 600});
                    reartypedText.setPosition(0, 600);
                    dedisplayButton.setPosition({0, 600});
                    dedisplayTextBox.setPosition({0, 600});
                    displayFordequeue.setPosition(0, 600);
                    DequeuerearButton.setPosition({0, 600});
                    DequeuefrontButton.setPosition({0, 600});
                    /////hiding the things of the Circular doubly list
                    insertBeginButtonCircularDoubly.setPosition({0, 600});
                    insertBeginTextBoxCircularDoubly.setPosition({0, 600});
                    insertBeginCircularDoublytypedText.setPosition(0, 600);
                    insertEndButtonCircularDoubly.setPosition({0, 600});
                    insertEndTextBoxCircularDoubly.setPosition({0, 600});
                    insertEndCircularDoublytypedText.setPosition(0, 600);
                    deleteButtonCircularDoublyList.setPosition({0, 600});
                    deleteTextBoxCircularDoublyList.setPosition({0, 600});
                    deleteCircularDoublytypedText.setPosition(0, 600);
                    displayButtonCircularDoublyList.setPosition({0, 600});
                    displayTextBoxCircularDoublyList.setPosition({0, 600});
                    displayForCircularDoublyList.setPosition(0, 600);
                    searchButtonCircularDoublyList.setPosition({0, 600});
                    searchTextBoxCircularDoublyList.setPosition({0, 600});
                    searchForCircularDoublyList.setPosition(0, 600);
                    //clearing the things of the DL
                    insertFrontButtondl.setPosition({0, 600});
                    displayFordl.setPosition(0, 600);
                    displayTextBoxdl.setPosition({0, 600});
                    displayButtondl.setPosition({0, 600});
                    tailtypedTextdl.setPosition(0, 600);

                    inserttailTextBoxdl.setPosition({0, 600});
                    inserttailButtondl.setPosition({0, 600});
                    insertFrontTextBoxdl.setPosition({0, 600});
                    fronttypedTextdl.setPosition(0, 600);
                    DeleterearButtondl.setPosition({0, 600});
                    DeletefrontButtondl.setPosition({0, 600});
                    /////////////////////////////////////////////////
                    //Insert
                    insertTextBoxCircularList.setPosition({60, 100});
                    typedTextInsertCircularList.setPosition(60, 100);
                    insertButtonCircularList.setPosition({60, 160});
                    //delete
                    deleteTextBoxCircularList.setPosition({60, 300});
                    typedTextDeleteCircularList.setPosition(60, 300);
                    deleteButtonCircularList.setPosition({60, 360});
                    //showing the display things
                    displayButtonCircularList.setPosition({395.5, 160});
                    displayTextBoxCircularList.setPosition({350, 110});
                    displayForCircularList.setPosition(350, 110);
                    //i had to put these things here cause the border was visible when they were at 0 600
                    displayTextBoxCircularList.setOutThick(5);
                    displayTextBoxCircularList.setOutColor(Color::Cyan);
                } else if (insertButtonCircularList.isMouseOver(window)) {
                    sound.play();
                    last = circularListObject.insertAtEnd(last, stoi(typedStringInsertCircularList));
                    typedStringInsertCircularList = "";
                    typedTextInsertCircularList.setString("");
                } else if (displayButtonCircularList.isMouseOver(window)) {
                    sound.play();
                    displayForCircularList.setString(circularListObject.traverseList(last));
                } else if (deleteButtonCircularList.isMouseOver(window)) {
                    sound.play();
                    if (typedStringDeleteCircularList != "" and circularListObject.noElements != 0) {
                        circularListObject.deleteNode(&last, stoi(typedStringDeleteCircularList));
                        typedStringDeleteCircularList = "";
                        typedTextDeleteCircularList.setString("");
                    }
                } else if (doubleEnded.isMouseOver(window)) {
                    sound.play();
                    nextScreen.setPosition(0, 600);
                    //claering
                    //array
                    typedText.setPosition(0, 600);
                    textOfSort.setPosition(0, 600);
                    sizetypedText.setPosition(0, 600);
                    DeltypedText.setPosition(0, 600);
                    insert.setPosition({0, 600});
                    sort.setPosition({0, 600});
                    sortB.setPosition({0, 600});
                    Delete.setPosition({0, 600});
                    DelB.setPosition({0, 600});
                    Enlarge.setPosition({0, 600});
                    Display.setPosition({0, 600});
                    inB.setPosition({0, 600});
                    DisplayB.setPosition({0, 600});
                    size.setPosition({0, 600});
                    sizeV.setPosition({0, 600});
                    /////STACK
                    pushButton.setPosition({0, 600});
                    pushTextBox.setPosition({0, 600});
                    typedTextStack.setPosition(0, 600);
                    displayButtonStack.setPosition({0, 600});
                    displayTextBoxStack.setPosition({0, 600});
                    displayForStack.setPosition(0, 600);
                    popButton.setPosition({0, 600});
                    peekButton.setPosition({0, 600});
                    peekTextBox.setPosition({0, 600});
                    peekTextForStack.setPosition(0, 600);
                    ////CIRCULAR QUEUEUE
                    enqueueButton.setPosition({0, 600});
                    enqueueTextBox.setPosition({0, 600});
                    typedTextEnqueue.setPosition(0, 600);
                    dequeueButton.setPosition({0, 600});
                    enqueueDisplayButton.setPosition({0, 600});
                    enqueueDisplayTextBox.setPosition({0, 600});
                    displayForCircularQueue.setPosition(0, 600);
                    ////CIRCULAR LIST
                    insertButtonCircularList.setPosition({0, 600});
                    insertTextBoxCircularList.setPosition({0, 600});
                    typedTextInsertCircularList.setPosition(0, 600);
                    deleteButtonCircularList.setPosition({0, 600});
                    deleteTextBoxCircularList.setPosition({0, 600});
                    typedTextDeleteCircularList.setPosition(0, 600);
                    displayButtonCircularList.setPosition({0, 600});
                    displayTextBoxCircularList.setPosition({0, 600});
                    displayForCircularList.setPosition(0, 600);
                    /////hiding the things of the Circular doubly list
                    insertBeginButtonCircularDoubly.setPosition({0, 600});
                    insertBeginTextBoxCircularDoubly.setPosition({0, 600});
                    insertBeginCircularDoublytypedText.setPosition(0, 600);
                    insertEndButtonCircularDoubly.setPosition({0, 600});
                    insertEndTextBoxCircularDoubly.setPosition({0, 600});
                    insertEndCircularDoublytypedText.setPosition(0, 600);
                    deleteButtonCircularDoublyList.setPosition({0, 600});
                    deleteTextBoxCircularDoublyList.setPosition({0, 600});
                    deleteCircularDoublytypedText.setPosition(0, 600);
                    displayButtonCircularDoublyList.setPosition({0, 600});
                    displayTextBoxCircularDoublyList.setPosition({0, 600});
                    displayForCircularDoublyList.setPosition(0, 600);
                    searchButtonCircularDoublyList.setPosition({0, 600});
                    searchTextBoxCircularDoublyList.setPosition({0, 600});
                    searchForCircularDoublyList.setPosition(0, 600);
                    //clearing the things of the DL
                    insertFrontButtondl.setPosition({0, 600});
                    displayFordl.setPosition(0, 600);
                    displayTextBoxdl.setPosition({0, 600});
                    displayButtondl.setPosition({0, 600});
                    tailtypedTextdl.setPosition(0, 600);

                    inserttailTextBoxdl.setPosition({0, 600});
                    inserttailButtondl.setPosition({0, 600});
                    insertFrontTextBoxdl.setPosition({0, 600});
                    fronttypedTextdl.setPosition(0, 600);
                    DeleterearButtondl.setPosition({0, 600});
                    DeletefrontButtondl.setPosition({0, 600});
                    /////////////////////////////////////////
                    //insert front
                    insertFrontTextBox.setPosition({60, 100});
                    fronttypedText.setPosition(60, 100);
                    insertFrontButton.setPosition({60, 160});
                    //insert rear
                    insertRearTextBox.setPosition({395.5, 360});
                    reartypedText.setPosition(395.5, 360);
                    insertRearButton.setPosition({395.5, 420});

                    //showing the display things
                    dedisplayButton.setPosition({395.5, 160});
                    dedisplayTextBox.setPosition({350, 110});
                    displayFordequeue.setPosition(350, 110);
                    //i had to put these things here cause the border was visible when they were at 0 600
                    dedisplayTextBox.setOutThick(5);
                    dedisplayTextBox.setOutColor(Color::Cyan);
                    //delete front
                    DequeuefrontButton.setPosition({60, 360});
                    //delete rear
                    DequeuerearButton.setPosition({60, 390});

                } else if (insertFrontButton.isMouseOver(window) and !fronttypedString.empty()) {
                    sound.play();
                    dq.insertFront(stoi(fronttypedString));
                    fronttypedString = "";
                    fronttypedText.setString("");
                } else if (insertRearButton.isMouseOver(window) and !reartypedString.empty()) {
                    sound.play();
                    dq.insertRear(stoi(reartypedString));
                    reartypedString = "";
                    reartypedText.setString("");
                } else if (dedisplayButton.isMouseOver(window)) {
                    sound.play();
                    displayFordequeue.setString(dq.display());
                } else if (DequeuefrontButton.isMouseOver(window)) {
                    sound.play();
                    dq.deleteFront();
                } else if (DequeuerearButton.isMouseOver(window)) {
                    sound.play();
                    dq.deleteRear();
                } else if (doublyCircular.isMouseOver(window)) {
                    sound.play();
                    nextScreen.setPosition(0, 600);
                    //clearing the window
                    ////array
                    typedText.setPosition(0, 600);
                    textOfSort.setPosition(0, 600);
                    sizetypedText.setPosition(0, 600);
                    DeltypedText.setPosition(0, 600);
                    insert.setPosition({0, 600});
                    sort.setPosition({0, 600});
                    sortB.setPosition({0, 600});
                    Delete.setPosition({0, 600});
                    DelB.setPosition({0, 600});
                    Enlarge.setPosition({0, 600});
                    Display.setPosition({0, 600});
                    inB.setPosition({0, 600});
                    DisplayB.setPosition({0, 600});
                    size.setPosition({0, 600});
                    sizeV.setPosition({0, 600});
                    /////STACK
                    pushButton.setPosition({0, 600});
                    pushTextBox.setPosition({0, 600});
                    typedTextStack.setPosition(0, 600);
                    displayButtonStack.setPosition({0, 600});
                    displayTextBoxStack.setPosition({0, 600});
                    displayForStack.setPosition(0, 600);
                    popButton.setPosition({0, 600});
                    peekButton.setPosition({0, 600});
                    peekTextBox.setPosition({0, 600});
                    peekTextForStack.setPosition(0, 600);
                    ////CIRCULAR QUEUEUE
                    enqueueButton.setPosition({0, 600});
                    enqueueTextBox.setPosition({0, 600});
                    typedTextEnqueue.setPosition(0, 600);
                    dequeueButton.setPosition({0, 600});
                    enqueueDisplayButton.setPosition({0, 600});
                    enqueueDisplayTextBox.setPosition({0, 600});
                    displayForCircularQueue.setPosition(0, 600);
                    ////CIRCULAR LIST
                    insertButtonCircularList.setPosition({0, 600});
                    insertTextBoxCircularList.setPosition({0, 600});
                    typedTextInsertCircularList.setPosition(0, 600);
                    deleteButtonCircularList.setPosition({0, 600});
                    deleteTextBoxCircularList.setPosition({0, 600});
                    typedTextDeleteCircularList.setPosition(0, 600);
                    displayButtonCircularList.setPosition({0, 600});
                    displayTextBoxCircularList.setPosition({0, 600});
                    displayForCircularList.setPosition(0, 600);
                    //deque
                    insertFrontButton.setPosition({0, 600});
                    insertFrontTextBox.setPosition({0, 600});
                    fronttypedText.setPosition(0, 600);
                    insertRearButton.setPosition({0, 600});
                    insertRearTextBox.setPosition({0, 600});
                    reartypedText.setPosition(0, 600);
                    dedisplayButton.setPosition({0, 600});
                    dedisplayTextBox.setPosition({0, 600});
                    displayFordequeue.setPosition(0, 600);
                    DequeuerearButton.setPosition({0, 600});
                    DequeuefrontButton.setPosition({0, 600});
                    //clearing the things of the DL
                    insertFrontButtondl.setPosition({0, 600});
                    displayFordl.setPosition(0, 600);
                    displayTextBoxdl.setPosition({0, 600});
                    displayButtondl.setPosition({0, 600});
                    tailtypedTextdl.setPosition(0, 600);

                    inserttailTextBoxdl.setPosition({0, 600});
                    inserttailButtondl.setPosition({0, 600});
                    insertFrontTextBoxdl.setPosition({0, 600});
                    fronttypedTextdl.setPosition(0, 600);
                    DeleterearButtondl.setPosition({0, 600});
                    DeletefrontButtondl.setPosition({0, 600});
                    /////////////////////////////////////////
                    //Insert Being
                    insertBeginTextBoxCircularDoubly.setPosition({60, 100});
                    insertBeginCircularDoublytypedText.setPosition(60, 100);
                    insertBeginButtonCircularDoubly.setPosition({60, 160});
                    //Insert End
                    insertEndTextBoxCircularDoubly.setPosition({60, 250});
                    insertEndCircularDoublytypedText.setPosition(60, 250);
                    insertEndButtonCircularDoubly.setPosition({60, 300});
                    //delete
                    deleteButtonCircularDoublyList.setPosition({60, 450});
                    deleteTextBoxCircularDoublyList.setPosition({60, 400});
                    deleteCircularDoublytypedText.setPosition(60, 400);
                    //showing the display things
                    displayButtonCircularDoublyList.setPosition({395.5, 160});
                    displayTextBoxCircularDoublyList.setPosition({350, 110});
                    displayForCircularDoublyList.setPosition(350, 110);
                    //i had to put these things here cause the border was visible when they were at 0 600
                    displayTextBoxCircularDoublyList.setOutThick(5);
                    displayTextBoxCircularDoublyList.setOutColor(Color::Cyan);
                    //search
                    searchButtonCircularDoublyList.setPosition({395.5, 450});
                    searchTextBoxCircularDoublyList.setPosition({395.5, 400});
                    searchForCircularDoublyList.setPosition(395.5, 400);
                } else if (insertBeginButtonCircularDoubly.isMouseOver(window) and
                           !insertBeginCircularDoublytypedString.empty()) {
                    sound.play();
                    cd.insert_begin(stoi(insertBeginCircularDoublytypedString));
                    insertBeginCircularDoublytypedString = "";
                    insertBeginCircularDoublytypedText.setString("");
                } else if (insertEndButtonCircularDoubly.isMouseOver(window) and
                           !insertEndCircularDoublytypedString.empty()) {
                    sound.play();
                    cd.insert_end(stoi(insertEndCircularDoublytypedString));
                    insertEndCircularDoublytypedString = "";
                    insertEndCircularDoublytypedText.setString("");
                } else if (deleteButtonCircularDoublyList.isMouseOver(window) and
                           !deleteCircularDoublytypedString.empty()) {
                    sound.play();
                    deleteCircularDoublytypedString = cd.delete_pos(stoi(deleteCircularDoublytypedString));
                } else if (displayButtonCircularDoublyList.isMouseOver(window)) {
                    sound.play();
                    displayForCircularDoublyList.setString(cd.display());
                } else if (searchButtonCircularDoublyList.isMouseOver(window) and !showSearch.empty()) {
                    sound.play();
                    showSearch = cd.search(stoi(showSearch));
                } else if (doubly.isMouseOver(window)) {
                    sound.play();
                    nextScreen.setPosition(0, 600);
                    ////array
                    typedText.setPosition(0, 600);
                    textOfSort.setPosition(0, 600);
                    sizetypedText.setPosition(0, 600);
                    DeltypedText.setPosition(0, 600);
                    insert.setPosition({0, 600});
                    sort.setPosition({0, 600});
                    sortB.setPosition({0, 600});
                    Delete.setPosition({0, 600});
                    DelB.setPosition({0, 600});
                    Enlarge.setPosition({0, 600});
                    Display.setPosition({0, 600});
                    inB.setPosition({0, 600});
                    DisplayB.setPosition({0, 600});
                    size.setPosition({0, 600});
                    sizeV.setPosition({0, 600});
                    /////STACK
                    pushButton.setPosition({0, 600});
                    pushTextBox.setPosition({0, 600});
                    typedTextStack.setPosition(0, 600);
                    displayButtonStack.setPosition({0, 600});
                    displayTextBoxStack.setPosition({0, 600});
                    displayForStack.setPosition(0, 600);
                    popButton.setPosition({0, 600});
                    peekButton.setPosition({0, 600});
                    peekTextBox.setPosition({0, 600});
                    peekTextForStack.setPosition(0, 600);
                    ////CIRCULAR QUEUEUE
                    enqueueButton.setPosition({0, 600});
                    enqueueTextBox.setPosition({0, 600});
                    typedTextEnqueue.setPosition(0, 600);
                    dequeueButton.setPosition({0, 600});
                    enqueueDisplayButton.setPosition({0, 600});
                    enqueueDisplayTextBox.setPosition({0, 600});
                    displayForCircularQueue.setPosition(0, 600);
                    ////CIRCULAR LIST
                    insertButtonCircularList.setPosition({0, 600});
                    insertTextBoxCircularList.setPosition({0, 600});
                    typedTextInsertCircularList.setPosition(0, 600);
                    deleteButtonCircularList.setPosition({0, 600});
                    deleteTextBoxCircularList.setPosition({0, 600});
                    typedTextDeleteCircularList.setPosition(0, 600);
                    displayButtonCircularList.setPosition({0, 600});
                    displayTextBoxCircularList.setPosition({0, 600});
                    displayForCircularList.setPosition(0, 600);
                    //deque
                    insertFrontButton.setPosition({0, 600});
                    insertFrontTextBox.setPosition({0, 600});
                    fronttypedText.setPosition(0, 600);
                    insertRearButton.setPosition({0, 600});
                    insertRearTextBox.setPosition({0, 600});
                    reartypedText.setPosition(0, 600);
                    dedisplayButton.setPosition({0, 600});
                    dedisplayTextBox.setPosition({0, 600});
                    displayFordequeue.setPosition(0, 600);
                    DequeuerearButton.setPosition({0, 600});
                    DequeuefrontButton.setPosition({0, 600});
                    //clearing the things of the DL
                    insertFrontButtondl.setPosition({0, 600});
                    displayFordl.setPosition(0, 600);
                    displayTextBoxdl.setPosition({0, 600});
                    displayButtondl.setPosition({0, 600});
                    tailtypedTextdl.setPosition(0, 600);

                    inserttailTextBoxdl.setPosition({0, 600});
                    inserttailButtondl.setPosition({0, 600});
                    insertFrontTextBoxdl.setPosition({0, 600});
                    fronttypedTextdl.setPosition(0, 600);
                    DeleterearButtondl.setPosition({0, 600});
                    DeletefrontButtondl.setPosition({0, 600});
                    /////hiding the things of the Circular doubly list
                    insertBeginButtonCircularDoubly.setPosition({0, 600});
                    insertBeginTextBoxCircularDoubly.setPosition({0, 600});
                    insertBeginCircularDoublytypedText.setPosition(0, 600);
                    insertEndButtonCircularDoubly.setPosition({0, 600});
                    insertEndTextBoxCircularDoubly.setPosition({0, 600});
                    insertEndCircularDoublytypedText.setPosition(0, 600);
                    deleteButtonCircularDoublyList.setPosition({0, 600});
                    deleteTextBoxCircularDoublyList.setPosition({0, 600});
                    deleteCircularDoublytypedText.setPosition(0, 600);
                    displayButtonCircularDoublyList.setPosition({0, 600});
                    displayTextBoxCircularDoublyList.setPosition({0, 600});
                    displayForCircularDoublyList.setPosition(0, 600);
                    searchButtonCircularDoublyList.setPosition({0, 600});
                    searchTextBoxCircularDoublyList.setPosition({0, 600});
                    searchForCircularDoublyList.setPosition(0, 600);
                    //////////////////////////////////////////////////


                    //insert front
                    insertFrontTextBoxdl.setPosition({60, 100});
                    fronttypedTextdl.setPosition(60, 100);
                    insertFrontButtondl.setPosition({60, 160});
                    //insert rear
                    inserttailTextBoxdl.setPosition({395.5, 360});
                    tailtypedTextdl.setPosition(395.5, 360);
                    inserttailButtondl.setPosition({395.5, 420});

                    //showing the display things
                    displayButtondl.setPosition({395.5, 160});
                    displayTextBoxdl.setPosition({350, 110});
                    displayFordl.setPosition(350, 110);
                    //i had to put these things here cause the border was visible when they were at 0 600
                    displayTextBoxdl.setOutThick(5);
                    displayTextBoxdl.setOutColor(Color::Cyan);
                    //delete front
                    DeletefrontButtondl.setPosition({60, 360});
                    //delete rear
                    DeleterearButtondl.setPosition({60, 390});
                } else if (insertFrontButtondl.isMouseOver(window) and !fronttypedStringdl.empty()) {
                    sound.play();
                    dl.insert_front(stoi(fronttypedStringdl));
                    fronttypedStringdl = "";
                    fronttypedTextdl.setString("");
                } else if (inserttailButtondl.isMouseOver(window) and !tailtypedStringdl.empty()) {
                    sound.play();
                    dl.insert_back(stoi(tailtypedStringdl));
                    tailtypedStringdl = "";
                    tailtypedTextdl.setString("");
                } else if (displayButtondl.isMouseOver(window)) {
                    sound.play();
                    displayFordl.setString(dl.display());

                } else if (DeletefrontButtondl.isMouseOver(window)) {
                    sound.play();
                    dl.delete_front();
                } else if (DeleterearButtondl.isMouseOver(window)) {
                    sound.play();
                    dl.delete_back();
                }

            } else if (event.type == Event::MouseMoved) { ///hovering yeah
                if (array.isMouseOver(window)) {
                    array.setOutThick(2);
                    array.setOutColor(Color::Cyan);
                } else {
                    array.setOutThick(0);
                    array.setOutColor(Color::Transparent);
                }
                if (linkedList.isMouseOver(window)) {
                    linkedList.setOutThick(2);
                    linkedList.setOutColor(Color::Cyan);
                } else {
                    linkedList.setOutThick(0);
                    linkedList.setOutColor(Color::Transparent);
                }
                if (circularListB.isMouseOver(window)) {
                    circularListB.setOutThick(2);
                    circularListB.setOutColor(Color::Magenta);
                } else {
                    circularListB.setOutThick(0);
                    circularListB.setOutColor(Color::Transparent);
                }
                if (doubly.isMouseOver(window)) {
                    doubly.setOutThick(2);
                    doubly.setOutColor(Color::Magenta);
                } else {
                    doubly.setOutThick(0);
                    doubly.setOutColor(Color::Transparent);
                }
                if (doublyCircular.isMouseOver(window)) {
                    doublyCircular.setOutThick(2);
                    doublyCircular.setOutColor(Color::Magenta);
                } else {
                    doublyCircular.setOutThick(0);
                    doublyCircular.setOutColor(Color::Transparent);
                }
                if (stackT.isMouseOver(window)) {
                    stackT.setOutThick(2);
                    stackT.setOutColor(Color::Cyan);
                } else {
                    stackT.setOutThick(0);
                    stackT.setOutColor(Color::Transparent);
                }
                if (queue.isMouseOver(window)) {
                    queue.setOutThick(2);
                    queue.setOutColor(Color::Cyan);
                } else {
                    queue.setOutThick(0);
                    queue.setOutColor(Color::Transparent);
                }
                if (circular.isMouseOver(window)) {
                    circular.setOutThick(2);
                    circular.setOutColor(Color::Green);
                } else {
                    circular.setOutThick(0);
                    circular.setOutColor(Color::Transparent);
                }
                if (doubleEnded.isMouseOver(window)) {
                    doubleEnded.setOutThick(2);
                    doubleEnded.setOutColor(Color::Green);
                } else {
                    doubleEnded.setOutThick(0);
                    doubleEnded.setOutColor(Color::Transparent);
                }
                if (startButton.isMouseOver(window)) {
                    startButton.setBackColor(Color(1, 159, 255));
                } else {
                    startButton.setBackColor(Color(178, 190, 181));
                }
                if (pushButton.isMouseOver(window)) {
                    pushButton.setBackColor(Color::Cyan);
                } else {
                    pushButton.setBackColor(Color(178, 190, 181));
                }
                if (displayButtonStack.isMouseOver(window)) {
                    displayButtonStack.setBackColor(Color::Cyan);
                } else {
                    displayButtonStack.setBackColor(Color(178, 190, 181));
                }
                if (popButton.isMouseOver(window)) {
                    popButton.setBackColor(Color::Cyan);
                } else {
                    popButton.setBackColor(Color(178, 190, 181));
                }
                if (peekButton.isMouseOver(window)) {
                    peekButton.setBackColor(Color::Cyan);
                } else {
                    peekButton.setBackColor(Color(178, 190, 181));
                }
                if (pushTextBox.isMouseOver(window)) {
                    pushTextBox.setOutThick(5);
                    pushTextBox.setOutColor(Color::Cyan);
                } else {
                    pushTextBox.setOutThick(0);
                    pushTextBox.setOutColor(Color::Transparent);
                }
                if (enqueueTextBox.isMouseOver(window)) {
                    enqueueTextBox.setOutThick(5);
                    enqueueTextBox.setOutColor(Color::Cyan);
                } else {
                    enqueueTextBox.setOutThick(0);
                    enqueueTextBox.setOutColor(Color::Transparent);
                }
                if (enqueueButton.isMouseOver(window)) {
                    enqueueButton.setBackColor(Color::Cyan);
                } else {
                    enqueueButton.setBackColor(Color(178, 190, 181));
                }
                if (dequeueButton.isMouseOver(window)) {
                    dequeueButton.setBackColor(Color::Cyan);
                } else {
                    dequeueButton.setBackColor(Color(178, 190, 181));
                }
                if (enqueueDisplayButton.isMouseOver(window)) {
                    enqueueDisplayButton.setBackColor(Color::Cyan);
                } else {
                    enqueueDisplayButton.setBackColor(Color(178, 190, 181));
                }
                if (insert.isMouseOver(window)) {
                    insert.setBackColor(Color::Cyan);
                } else {
                    insert.setBackColor(Color(178, 190, 181));
                }
                if (inB.isMouseOver(window)) {
                    inB.setOutThick(5);
                    inB.setOutColor(Color::Cyan);
                } else {
                    inB.setOutThick(0);
                    inB.setOutColor(Color::Transparent);
                }
                if (Delete.isMouseOver(window)) {
                    Delete.setBackColor(Color::Cyan);
                } else {
                    Delete.setBackColor(Color(178, 190, 181));
                }
                if (DelB.isMouseOver(window)) {
                    DelB.setOutThick(5);
                    DelB.setOutColor(Color::Cyan);
                } else {
                    DelB.setOutThick(0);
                    DelB.setOutColor(Color::Transparent);
                }
                if (Enlarge.isMouseOver(window)) {
                    Enlarge.setBackColor(Color::Cyan);
                } else {
                    Enlarge.setBackColor(Color(178, 190, 181));
                }
                if (size.isMouseOver(window)) {
                    size.setBackColor(Color::Cyan);
                } else {
                    size.setBackColor(Color(178, 190, 181));
                }
                if (sizeV.isMouseOver(window)) {
                    sizeV.setOutThick(5);
                    sizeV.setOutColor(Color::Cyan);
                } else {
                    sizeV.setOutThick(0);
                    sizeV.setOutColor(Color::Transparent);
                }
                if (sort.isMouseOver(window)) {
                    sort.setBackColor(Color::Cyan);
                } else {
                    sort.setBackColor(Color(178, 190, 181));
                }
                if (Display.isMouseOver(window)) {
                    Display.setBackColor(Color::Cyan);
                } else {
                    Display.setBackColor(Color(178, 190, 181));
                }
                if (insertButtonCircularList.isMouseOver(window)) {
                    insertButtonCircularList.setBackColor(Color::Cyan);
                } else {
                    insertButtonCircularList.setBackColor(Color(178, 190, 181));
                }
                if (insertTextBoxCircularList.isMouseOver(window)) {
                    insertTextBoxCircularList.setOutThick(5);
                    insertTextBoxCircularList.setOutColor(Color::Cyan);
                } else {
                    insertTextBoxCircularList.setOutThick(0);
                    insertTextBoxCircularList.setOutColor(Color::Transparent);
                }
                if (deleteButtonCircularList.isMouseOver(window)) {
                    deleteButtonCircularList.setBackColor(Color::Cyan);
                } else {
                    deleteButtonCircularList.setBackColor(Color(178, 190, 181));
                }
                if (deleteTextBoxCircularList.isMouseOver(window)) {
                    deleteTextBoxCircularList.setOutThick(5);
                    deleteTextBoxCircularList.setOutColor(Color::Cyan);
                } else {
                    deleteTextBoxCircularList.setOutThick(0);
                    deleteTextBoxCircularList.setOutColor(Color::Transparent);
                }
                if (displayButtonCircularList.isMouseOver(window)) {
                    displayButtonCircularList.setBackColor(Color::Cyan);
                } else {
                    displayButtonCircularList.setBackColor(Color(178, 190, 181));
                }
                if (insertFrontButton.isMouseOver(window)) {
                    insertFrontButton.setBackColor(Color::Cyan);
                } else {
                    insertFrontButton.setBackColor(Color(178, 190, 181));
                }
                if (insertRearButton.isMouseOver(window)) {
                    insertRearButton.setBackColor(Color::Cyan);
                } else {
                    insertRearButton.setBackColor(Color(178, 190, 181));
                }
                if (dedisplayButton.isMouseOver(window)) {
                    dedisplayButton.setBackColor(Color::Cyan);
                } else {
                    dedisplayButton.setBackColor(Color(178, 190, 181));
                }
                if (DequeuerearButton.isMouseOver(window)) {
                    DequeuerearButton.setBackColor(Color::Cyan);
                } else {
                    DequeuerearButton.setBackColor(Color(178, 190, 181));
                }
                if (DequeuefrontButton.isMouseOver(window)) {
                    DequeuefrontButton.setBackColor(Color::Cyan);
                } else {
                    DequeuefrontButton.setBackColor(Color(178, 190, 181));
                }
                if (insertFrontTextBox.isMouseOver(window)) {
                    insertFrontTextBox.setOutThick(5);
                    insertFrontTextBox.setOutColor(Color::Cyan);
                } else {
                    insertFrontTextBox.setOutThick(0);
                    insertFrontTextBox.setOutColor(Color::Transparent);
                }
                if (insertRearTextBox.isMouseOver(window)) {
                    insertRearTextBox.setOutThick(5);
                    insertRearTextBox.setOutColor(Color::Cyan);
                } else {
                    insertRearTextBox.setOutThick(0);
                    insertRearTextBox.setOutColor(Color::Transparent);
                }
                if (displayButtonCircularDoublyList.isMouseOver(window)) {
                    displayButtonCircularDoublyList.setBackColor(Color::Cyan);
                } else {
                    displayButtonCircularDoublyList.setBackColor(Color(178, 190, 181));
                }
                if (insertBeginButtonCircularDoubly.isMouseOver(window)) {
                    insertBeginButtonCircularDoubly.setBackColor(Color::Cyan);
                } else {
                    insertBeginButtonCircularDoubly.setBackColor(Color(178, 190, 181));
                }
                if (insertBeginTextBoxCircularDoubly.isMouseOver(window)) {
                    insertBeginTextBoxCircularDoubly.setOutThick(5);
                    insertBeginTextBoxCircularDoubly.setOutColor(Color::Cyan);
                } else {
                    insertBeginTextBoxCircularDoubly.setOutThick(0);
                    insertBeginTextBoxCircularDoubly.setOutColor(Color::Transparent);
                }
                if (insertEndButtonCircularDoubly.isMouseOver(window)) {
                    insertEndButtonCircularDoubly.setBackColor(Color::Cyan);
                } else {
                    insertEndButtonCircularDoubly.setBackColor(Color(178, 190, 181));
                }
                if (insertEndTextBoxCircularDoubly.isMouseOver(window)) {
                    insertEndTextBoxCircularDoubly.setOutThick(5);
                    insertEndTextBoxCircularDoubly.setOutColor(Color::Cyan);
                } else {
                    insertEndTextBoxCircularDoubly.setOutThick(0);
                    insertEndTextBoxCircularDoubly.setOutColor(Color::Transparent);
                }
                if (deleteButtonCircularDoublyList.isMouseOver(window)) {
                    deleteButtonCircularDoublyList.setBackColor(Color::Cyan);
                } else {
                    deleteButtonCircularDoublyList.setBackColor(Color(178, 190, 181));
                }
                if (deleteTextBoxCircularDoublyList.isMouseOver(window)) {
                    deleteTextBoxCircularDoublyList.setOutThick(5);
                    deleteTextBoxCircularDoublyList.setOutColor(Color::Cyan);
                } else {
                    deleteTextBoxCircularDoublyList.setOutThick(0);
                    deleteTextBoxCircularDoublyList.setOutColor(Color::Transparent);
                }
                if (searchButtonCircularDoublyList.isMouseOver(window)) {
                    searchButtonCircularDoublyList.setBackColor(Color::Cyan);
                } else {
                    searchButtonCircularDoublyList.setBackColor(Color(178, 190, 181));
                }
                if (searchTextBoxCircularDoublyList.isMouseOver(window)) {
                    searchTextBoxCircularDoublyList.setOutThick(5);
                    searchTextBoxCircularDoublyList.setOutColor(Color::Cyan);
                } else {
                    searchTextBoxCircularDoublyList.setOutThick(0);
                    searchTextBoxCircularDoublyList.setOutColor(Color::Transparent);
                }
                if (insertFrontButtondl.isMouseOver(window)) {
                    insertFrontButtondl.setBackColor(Color::Cyan);
                } else {
                    insertFrontButtondl.setBackColor(Color(178, 190, 181));
                }
                if (inserttailButtondl.isMouseOver(window)) {
                    inserttailButtondl.setBackColor(Color::Cyan);
                } else {
                    inserttailButtondl.setBackColor(Color(178, 190, 181));
                }
                if (displayButtondl.isMouseOver(window)) {
                    displayButtondl.setBackColor(Color::Cyan);
                } else {
                    displayButtondl.setBackColor(Color(178, 190, 181));
                }
                if (DeletefrontButtondl.isMouseOver(window)) {
                    DeletefrontButtondl.setBackColor(Color::Cyan);
                } else {
                    DeletefrontButtondl.setBackColor(Color(178, 190, 181));
                }
                if (DeleterearButtondl.isMouseOver(window)) {
                    DeleterearButtondl.setBackColor(Color::Cyan);
                } else {
                    DeleterearButtondl.setBackColor(Color(178, 190, 181));
                }
                if (displayButtondl.isMouseOver(window)) {
                    displayButtondl.setBackColor(Color::Cyan);
                } else {
                    displayButtondl.setBackColor(Color(178, 190, 181));
                }
                if (insertFrontTextBoxdl.isMouseOver(window)) {
                    insertFrontTextBoxdl.setOutThick(5);
                    insertFrontTextBoxdl.setOutColor(Color::Cyan);
                } else {
                    insertFrontTextBoxdl.setOutThick(0);
                    insertFrontTextBoxdl.setOutColor(Color::Transparent);
                }
                if (inserttailTextBoxdl.isMouseOver(window)) {
                    inserttailTextBoxdl.setOutThick(5);
                    inserttailTextBoxdl.setOutColor(Color::Cyan);
                } else {
                    inserttailTextBoxdl.setOutThick(0);
                    inserttailTextBoxdl.setOutColor(Color::Transparent);
                }
            } else if (pushTextBox.isMouseOver(window)) { //pushing
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128 and event.text.unicode != '\b' and event.text.unicode != 13) {
                        typedStringStack += static_cast<char>(event.text.unicode);
                    } else if (event.text.unicode == '\b' and !typedStringStack.empty()) { // backspace
                        typedStringStack.erase(typedStringStack.size() - 1, 1);
                    }
                }
            } else if (enqueueTextBox.isMouseOver(window)) { //pushing
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128 and event.text.unicode != '\b' and event.text.unicode != 13) {
                        typedStringEnqueue += static_cast<char>(event.text.unicode);
                    } else if (event.text.unicode == '\b' and !typedStringEnqueue.empty()) { // backspace
                        typedStringEnqueue.erase(typedStringEnqueue.size() - 1, 1);
                    }
                }
            } else if (inB.isMouseOver(window)) {
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128 and event.text.unicode != '\b' and event.text.unicode != 13) {
                        typedString += static_cast<char>(event.text.unicode);
                    } else if (event.text.unicode == '\b' and !typedString.empty()) { // backspace
                        typedString.erase(typedString.size() - 1, 1);
                    }
                }
            } else if (DelB.isMouseOver(window)) {
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128 and event.text.unicode != '\b' and event.text.unicode != 13) {
                        DeltypedString += static_cast<char>(event.text.unicode);
                    } else if (event.text.unicode == '\b' and !DeltypedString.empty()) { // backspace
                        DeltypedString.erase(DeltypedString.size() - 1, 1);
                    }
                }
            } else if (sizeV.isMouseOver(window)) {
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128 and event.text.unicode != '\b' and event.text.unicode != 13) {
                        sizetypedString += static_cast<char>(event.text.unicode);
                    } else if (event.text.unicode == '\b' and !sizetypedString.empty()) { // backspace
                        sizetypedString.erase(sizetypedString.size() - 1, 1);
                    }
                }
            } else if (insertTextBoxCircularList.isMouseOver(window)) { //pushing
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128 and event.text.unicode != '\b' and event.text.unicode != 13) {
                        typedStringInsertCircularList += static_cast<char>(event.text.unicode);
                    } else if (event.text.unicode == '\b' and !typedStringInsertCircularList.empty()) { // backspace
                        typedStringInsertCircularList.erase(typedStringInsertCircularList.size() - 1, 1);
                    }
                }
            } else if (deleteTextBoxCircularList.isMouseOver(window)) { //pushing
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128 and event.text.unicode != '\b' and event.text.unicode != 13) {
                        typedStringDeleteCircularList += static_cast<char>(event.text.unicode);
                    } else if (event.text.unicode == '\b' and !typedStringDeleteCircularList.empty()) { // backspace
                        typedStringDeleteCircularList.erase(typedStringDeleteCircularList.size() - 1, 1);
                    }
                }
            } else if (insertFrontTextBox.isMouseOver(window)) { //insert front
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128 and event.text.unicode != '\b' and event.text.unicode != 13) {
                        fronttypedString += static_cast<char>(event.text.unicode);
                    } else if (event.text.unicode == '\b' and !fronttypedString.empty()) { // backspace
                        fronttypedString.erase(fronttypedString.size() - 1, 1);
                    }
                }
            } else if (insertRearTextBox.isMouseOver(window)) { //insert rear
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128 and event.text.unicode != '\b' and event.text.unicode != 13) {
                        reartypedString += static_cast<char>(event.text.unicode);
                    } else if (event.text.unicode == '\b' and !reartypedString.empty()) { // backspace
                        reartypedString.erase(reartypedString.size() - 1, 1);
                    }
                }
            } else if (insertBeginTextBoxCircularDoubly.isMouseOver(window)) {
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128 and event.text.unicode != '\b' and event.text.unicode != 13) {
                        insertBeginCircularDoublytypedString += static_cast<char>(event.text.unicode);
                    } else if (event.text.unicode == '\b' and
                               !insertBeginCircularDoublytypedString.empty()) { // backspace
                        insertBeginCircularDoublytypedString.erase(insertBeginCircularDoublytypedString.size() - 1, 1);
                    }
                }
            } else if (insertEndTextBoxCircularDoubly.isMouseOver(window)) {
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128 and event.text.unicode != '\b' and event.text.unicode != 13) {
                        insertEndCircularDoublytypedString += static_cast<char>(event.text.unicode);
                    } else if (event.text.unicode == '\b' and
                               !insertEndCircularDoublytypedString.empty()) { // backspace
                        insertEndCircularDoublytypedString.erase(insertEndCircularDoublytypedString.size() - 1, 1);
                    }
                }
            } else if (deleteTextBoxCircularDoublyList.isMouseOver(window)) {
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128 and event.text.unicode != '\b' and event.text.unicode != 13) {
                        deleteCircularDoublytypedString += static_cast<char>(event.text.unicode);
                    } else if (event.text.unicode == '\b' and !deleteCircularDoublytypedString.empty()) { // backspace
                        deleteCircularDoublytypedString.erase(deleteCircularDoublytypedString.size() - 1, 1);
                    }
                }
            } else if (searchTextBoxCircularDoublyList.isMouseOver(window)) {
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128 and event.text.unicode != '\b' and event.text.unicode != 13) {
                        showSearch += static_cast<char>(event.text.unicode);
                    } else if (event.text.unicode == '\b' and !showSearch.empty()) { // backspace
                        showSearch.erase(showSearch.size() - 1, 1);
                    }
                }
            } else if (insertFrontTextBoxdl.isMouseOver(window)) { //insert front
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128 and event.text.unicode != '\b' and event.text.unicode != 13) {
                        fronttypedStringdl += static_cast<char>(event.text.unicode);
                    } else if (event.text.unicode == '\b' and !fronttypedStringdl.empty()) { // backspace
                        fronttypedStringdl.erase(fronttypedStringdl.size() - 1, 1);
                    }
                }
            } else if (inserttailTextBoxdl.isMouseOver(window)) { //insert rear
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128 and event.text.unicode != '\b' and event.text.unicode != 13) {
                        tailtypedStringdl += static_cast<char>(event.text.unicode);
                    } else if (event.text.unicode == '\b' and !tailtypedStringdl.empty()) { // backspace
                        tailtypedStringdl.erase(tailtypedStringdl.size() - 1, 1);
                    }
                }
            }
        }
        window.clear();
        pushTextBox.drawTo(window);
        window.draw(typedTextStack);
        typedTextStack.setString(typedStringStack);
        typedTextEnqueue.setString(typedStringEnqueue);
        pushButton.drawTo(window);
        //////DRAWING
        //window.draw(splashSprit);
        //splashSprit.setTexture(splashTexture);
        window.draw(welcomeScreenText);
        window.draw(nextScreen);
        array.drawTo(window);
        linkedList.drawTo(window);
        circularListB.drawTo(window);
        doubly.drawTo(window);
        doublyCircular.drawTo(window);
        stackT.drawTo(window);
        queue.drawTo(window);
        circular.drawTo(window);
        doubleEnded.drawTo(window);
        //stack drawings
        displayButtonStack.drawTo(window);
        displayTextBoxStack.drawTo(window);
        window.draw(displayForStack);
        //drawing Pop Button
        popButton.drawTo(window);
        //drawing peek things
        peekButton.drawTo(window);
        peekTextBox.drawTo(window);
        window.draw(peekTextForStack);
        startButton.drawTo(window);
        enqueueButton.drawTo(window);
        enqueueTextBox.drawTo(window);
        window.draw(typedTextEnqueue);
        dequeueButton.drawTo(window);
        enqueueDisplayButton.drawTo(window);
        enqueueDisplayTextBox.drawTo(window);
        window.draw(displayForCircularQueue);
        ///circular list drawings
        insertButtonCircularList.drawTo(window);
        insertTextBoxCircularList.drawTo(window);
        window.draw(typedTextInsertCircularList);
        typedTextInsertCircularList.setString(typedStringInsertCircularList);
        deleteButtonCircularList.drawTo(window);
        deleteTextBoxCircularList.drawTo(window);
        window.draw(typedTextDeleteCircularList);
        typedTextDeleteCircularList.setString(typedStringDeleteCircularList);
        displayButtonCircularList.drawTo(window);
        displayTextBoxCircularList.drawTo(window);
        window.draw(displayForCircularList);
        ///array drawings
        inB.drawTo(window);
        window.draw(typedText);
        typedText.setString(typedString);
        insert.drawTo(window);
        //Sort----------------------------------------------------
        sort.drawTo(window);
        sortB.drawTo(window);
        window.draw(textOfSort);
        //delet-----------------------------------w
        DelB.drawTo(window);
        window.draw(DeltypedText);
        DeltypedText.setString(DeltypedString);
        Delete.drawTo(window);
        //Enlarge-----------------------------------------------------------------------
        Enlarge.drawTo(window);
        //display--------------------------------------------------------
        Display.drawTo(window);
        DisplayB.drawTo(window);
        window.draw(displayText);
        //size----------------------------------
        sizeV.drawTo(window);
        window.draw(sizetypedText);
        sizetypedText.setString(sizetypedString);
        size.drawTo(window);

////////////////////////////////////////////////
        insertFrontButton.drawTo(window);
        insertFrontTextBox.drawTo(window);
        window.draw(fronttypedText);

        insertRearTextBox.drawTo(window);
        insertRearButton.drawTo(window);
        window.draw(reartypedText);

        dedisplayButton.drawTo(window);
        dedisplayTextBox.drawTo(window);

        window.draw(displayFordequeue);
        DequeuefrontButton.drawTo(window);
        DequeuerearButton.drawTo(window);
        fronttypedText.setString(fronttypedString);
        reartypedText.setString(reartypedString);
        /////hiding the things of the Circular doubly list
        insertBeginButtonCircularDoubly.drawTo(window);
        insertBeginTextBoxCircularDoubly.drawTo(window);
        window.draw(insertBeginCircularDoublytypedText);

        insertEndTextBoxCircularDoubly.drawTo(window);
        insertEndButtonCircularDoubly.drawTo(window);
        window.draw(insertEndCircularDoublytypedText);

        deleteButtonCircularDoublyList.drawTo(window);
        deleteTextBoxCircularDoublyList.drawTo(window);
        window.draw(deleteCircularDoublytypedText);

        displayButtonCircularDoublyList.drawTo(window);
        displayTextBoxCircularDoublyList.drawTo(window);
        window.draw(displayForCircularDoublyList);

        searchTextBoxCircularDoublyList.drawTo(window);
        searchButtonCircularDoublyList.drawTo(window);
        window.draw(searchForCircularDoublyList);
        insertBeginCircularDoublytypedText.setString(insertBeginCircularDoublytypedString);
        insertEndCircularDoublytypedText.setString(insertEndCircularDoublytypedString);
        deleteCircularDoublytypedText.setString(deleteCircularDoublytypedString);
        searchForCircularDoublyList.setString(showSearch);
        //////////////////////////////////////
        insertFrontTextBoxdl.drawTo(window);
        window.draw(fronttypedTextdl);
        fronttypedTextdl.setString(fronttypedStringdl);
        insertFrontButtondl.drawTo(window);
        //
        inserttailTextBoxdl.drawTo(window);
        window.draw(tailtypedTextdl);
        tailtypedTextdl.setString(tailtypedStringdl);
        inserttailButtondl.drawTo(window);
        //


        displayTextBoxdl.drawTo(window);
        displayButtondl.drawTo(window);
        window.draw(displayFordl);

        DeletefrontButtondl.drawTo(window);
        DeleterearButtondl.drawTo(window);

        window.display();
    }
}