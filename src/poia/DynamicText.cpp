#include "DynamicText.h"



DynamicText::DynamicText()
{

}

DynamicText::DynamicText(Rect newPosition)
{
	position = newPosition;
}


DynamicText::~DynamicText()
{
}

void DynamicText::UpdateText(Text newText)
{
	text = newText;

}

void DynamicText::Draw(Renderer* myRenderer)
{
	
	myRenderer->OverwritteTextureText(text);
	myRenderer->PushImage(text.id, { position.x, position.y, position.w, position.h });

}
