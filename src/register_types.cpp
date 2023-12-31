/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#include "register_types.h"

#include <gdextension_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "example.h"
#include "tests.h"

#include "action.h"
#include "cue.h"
#include "player.h"
#include "character.h"
#include "animator.h"
#include "game.h"
#include "game_mode.h"
#include "state.h"
#include "property.h"
#include "movement.h"
#include "cinema.h"

using namespace godot;

void initialize_example_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	ClassDB::register_class<ExampleRef>();
	ClassDB::register_class<ExampleMin>();
	ClassDB::register_class<Example>();
	ClassDB::register_class<ExampleVirtual>(true);
	ClassDB::register_abstract_class<ExampleAbstract>();

	ClassDB::register_class<Action>();
	ClassDB::register_class<Cue>();
	ClassDB::register_class<Character>();
	ClassDB::register_class<Player>();
	ClassDB::register_class<Animator>();
	ClassDB::register_class<Game>();
	ClassDB::register_class<GameMode>();
	ClassDB::register_class<State>();
	ClassDB::register_class<Property>();
	ClassDB::register_class<Movement>();
	ClassDB::register_class<Cinema>();
	
}

void uninitialize_example_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_example_module);
	init_obj.register_terminator(uninitialize_example_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}