#include "CMouse.h"
#include "Global.h"

CMouse::CMouse(bool rangeFlag){
	mouse = new CSpriteSceneNode("image/mouse/mouse.png");
	//pushSceneNode(0,mouse);
	mouse->pos = D3DXVECTOR2( -mouse->width/2.f , -mouse->height/2.f );
	rect = Rect(-mouse->width/2.f, -mouse->height/2.f, mouse->width/2.f, mouse->height/2.f);

	mouse2 = new CSpriteSceneNode("image/mouse/mouse2.png");
	//pushSceneNode(1,mouse2);
	

	if(rangeFlag == true){
		range = new CSpriteSceneNode("image/range.png");
		pushSceneNode(1,range);
		range->pos = D3DXVECTOR2(-range->width/2.f , -range->width/2.f);
	}
	mouseFlag = false;
}
CMouse::~CMouse(){

}
void CMouse::render(){
	ISceneNode::render();

}
void CMouse::update(float eTime){
	ISceneNode::update(eTime);
	
	mousePos = setMousePos();
	pos = D3DXVECTOR2(mousePos.x, mousePos.y);
	if(mouseFlag == false)
	{
		pushSceneNode(0,mouse);
		rect = Rect(-mouse->width/2.f, -mouse->height/2.f, mouse->width/2.f, mouse->height/2.f);
		
	}
	else{
		pushSceneNode(0,mouse2);
		pos = D3DXVECTOR2(mousePos.x, mousePos.y);
		rect = Rect(-mouse2->width/2.f, -mouse2->height/2.f, mouse2->width/2.f, mouse2->height/2.f);
		range->visible = false;
	}

}