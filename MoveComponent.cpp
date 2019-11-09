#include "MoveComponent.h"
#include "Actor.h"

MoveComponent::MoveComponent(class Actor* newOwner, int updateOrder)
	:Component(newOwner, updateOrder),
	horizontalMove(0.0f),
	verticalMove(0.0f)
{
	game = newOwner->GetGame();
}

void MoveComponent::Update(float deltaTime){
	if (!Math::NearZero(verticalMove)) {
		Vector3 position = owner->GetPosition();
		int row = (int)(position.x / 100);
		int col = (int)(position.y / 100);

		if (game->IsWalkable(row + verticalMove / 100, col)) {
			cout << "Is Walkable" << endl;
			Vector3 pos = owner->GetPosition() + Vector3(verticalMove, .0f, .0f);
			owner->SetPosition(pos);
			cout << "Current row,col: " << pos.x / 100 << " " << pos.y / 100 << endl;
		}
		else {
			cout << "Not Walkable" << endl;
		}
	}
	else if (!Math::NearZero(horizontalMove)) {
		Vector3 position = owner->GetPosition();
		int row = (int)(position.x / 100);
		int col = (int)(position.y / 100);

		if (game->IsWalkable(row, col + -horizontalMove / 100)) {
			cout << "Is Walkable" << endl;
			Vector3 pos = owner->GetPosition() + Vector3(.0f, -horizontalMove, .0f);
			owner->SetPosition(pos);
			cout << "Current row,col: " << pos.x / 100 << " " << pos.y / 100 << endl;
		}
		else {
			cout << "Is Not Walkable" << endl;
		}
	}
}
