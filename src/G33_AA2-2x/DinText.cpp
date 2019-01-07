#include "DinText.h"



DinText::DinText()
{

}

DinText::DinText(Rect newPosition)
{
	position = newPosition;
}


DinText::~DinText()
{
}

void DinText::UpdateText(Text newText)
{
	text = newText;

}

void DinText::Draw(Renderer* myRenderer)
{
	
	myRenderer->OverwritteTextureText(text);
	myRenderer->PushImage(text.id, { position.x, position.y, position.w, position.h });

}
