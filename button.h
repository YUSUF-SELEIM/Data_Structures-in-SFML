////
//// Created by yusuf on 12/11/22.
////
//
#ifndef DSAPRO_BUTTON_H
#define DSAPRO_BUTTON_H


using namespace sf;
using namespace std;
class Button{
public:
    Button(){

    }
    Button(string t, Vector2f size, int charSize, Color bgColor, Texture &texture, Font &font){
        text.setString(t);
        text.setColor(Color::Black);
        text.setCharacterSize(charSize);
        text.setFont(font);
        button.setSize(size);
        button.setFillColor(bgColor);
        button.setPosition(0.f, 500.f);
        button.setTexture(&texture);
    }

    void setBackColor(Color color){
        button.setFillColor(color);
    }
    void setTextColor(Color color){
        text.setColor(color);
    }
    void setString(string newString){
        text.setString(newString);
    }
    void setPosition(Vector2f pos){
        button.setPosition(pos);
        float xPos=(pos.x+button.getGlobalBounds().width/2)-(text.getGlobalBounds().width/2);
        float yPos = (pos.y + button.getLocalBounds().height /2)-(text.getGlobalBounds().height/2)-3;
        text.setPosition({xPos, yPos});
    }

    void drawTo(RenderWindow &window){
        window.draw(button);
        window.draw(text);
    }
    void setOutColor(Color outColor){
        button.setOutlineColor(outColor);
    }
    void setOutThick(float outThick){
        button.setOutlineThickness(outThick);
    }
    bool isMouseOver(RenderWindow &window){
        float mouseX = Mouse::getPosition(window).x;
        float mouseY = Mouse::getPosition(window).y;
        float btnPosX = button.getPosition().x;
        float btnPosY = button.getPosition().y;
        float btnxPosWidth = button.getPosition().x + button.getLocalBounds().width;
        float btnyPosWidth = button.getPosition().y + button.getLocalBounds().height;
        if(mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosWidth && mouseY > btnPosY){
            return true;
        }
        return false;
    }
private:
    RectangleShape button;
    Text text;
};

#endif //DSAPRO_BUTTON_H