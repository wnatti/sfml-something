#include "TextureLoader.h"


TextureLoader::TextureLoader(void)
{
	//Peliss� luodaan vain yksi TextureLoader,
	//joten kuva ladataan tekstuurin vain kerran peliss� t�ss� kohtaa,
	//jokainen assetti k�ytt�� t�t� samaa tekstuuria peliss�, mutta eri kohtia siit�

	std::cout << "TextureLoader created" << std::endl;
	Texture* t = new Texture;
	t->loadFromFile("Textures.png");
	_atlas = t;
	IntRect torso(38,0,10,17);
	IntRect head(1,1,31,31);
	IntRect bullet(33,0,4,4);
	_rectangles.insert((std::make_pair("head",head)));
	_rectangles.insert((std::make_pair("bullet",bullet)));
	_rectangles.insert((std::make_pair("torso",torso)));
}



//hakee sy�tetyll� nimell�(string) int rectanglen, joka antaa tekstuurin kordinaatit atlaksesta
IntRect& TextureLoader::getRect(std::string name)
{
	std::multimap<std::string,IntRect>::iterator it;
	it = _rectangles.find(name);
	return (*it).second;
	//**tee checkki t�h�n l�ytyyk� nimell� mit��n**
}

//Funktio jolla haetaan, oikea IntRect(*katso getRect())
//sy�tt�m�ll� parametriksi haettava tekstuurin p�tk�
Sprite& TextureLoader::getSprite(std::string name)
{
	_sprite.setTexture(*_atlas);
	_sprite.setTextureRect(getRect(name));
	return _sprite;
}


TextureLoader::~TextureLoader(void)
{

}
