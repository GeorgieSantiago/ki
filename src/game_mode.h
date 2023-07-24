#ifndef KI_GAME_MODE_H
#define KI_GAME_MODE_H

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/variant/variant.hpp>

using namespace godot;

class GameMode : public Node3D
{
	GDCLASS(GameMode, Node3D);
protected:
	static void _bind_methods();
public:
	Ref<PackedScene> player_prefab;
	Ref<PackedScene> get_player_prefab();
	void set_player_prefab(Ref<PackedScene> scene);
	
	Node* player_node;
	//Idk yet
	void _ready() override;
};

#endif