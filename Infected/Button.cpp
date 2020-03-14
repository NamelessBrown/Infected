#include "Button.h"

//Construstors / Destructors
/* Button::Button(const sf::Vector2f& position, const std::string& buttonName, const sf::Vector2f& buttonSize, const sf::Color& buttonColor)
	:mClicked(false)
{
	mFont.loadFromFile("Font/fast_money.ttf");
	mText.setFont(mFont);
	mText.setString(buttonName);

	mText.setPosition(position.x + 50, position.y);

	mButtonRect.setPosition(position);

	mButtonRect.setFillColor(buttonColor);
	mButtonRect.setSize(buttonSize);
} */

Button::Button(const sf::Vector2f& position, const std::string& buttonName, const sf::Color& buttonColor, const sf::Vector2f& buttonSize, const std::string fontFileName, const int textpositionX)
	:mClicked(false)
	/*
		The textpositionX is how far you want the text position in the X direction to be from the GUI button. 
	*/
{
	mFont.loadFromFile(fontFileName);
	mText.setFont(mFont);
	mText.setString(buttonName);
	mText.setCharacterSize(20);

	mText.setPosition(position.x + textpositionX, position.y);

	mButtonRect.setPosition(position);

	mButtonRect.setFillColor(buttonColor);
	mButtonRect.setSize(buttonSize);
}

Button::~Button()
{
}

//Checks to see if the sprite has been clicked on. Returns bool is the mouse is clicked and the sprite is on the button!
bool Button::IsClicked(const sf::Sprite& sprite)
{
	const sf::Mouse mouse;

	if (mButtonRect.getGlobalBounds().contains(sprite.getPosition()) && mouse.isButtonPressed(sf::Mouse::Left) && !mClicked)
	{
		mClicked = true;
	}
	else
		mClicked = false;


	return mClicked;
}

bool Button::IsClicked(const sf::Vector2i& mousePosition)
{
	const sf::Mouse mouse;

	if (mButtonRect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)) && mouse.isButtonPressed(sf::Mouse::Left) && !mClicked)
	{
		mClicked = true;
	}
	else
		mClicked = false;


	return mClicked;
}

void Button::MovePosition(const sf::Vector2f& newPosition)
{
	mButtonRect.setPosition(newPosition);
}

void Button::ChangeedFont(const std::string fontFileName)
{
	mFont.loadFromFile(fontFileName);
	mText.setFont(mFont);
}

//Draws all things that needs to be draw with the buton class
void Button::Draw(sf::RenderTarget& target)
{
	target.draw(mButtonRect);
	target.draw(mText);
}

