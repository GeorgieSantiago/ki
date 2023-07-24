extends Cue

var actions = InputMap.get_actions()
@export var input_action: String
@export var on_released: bool

func _input(event):
	if on_released:
		if event.is_action_released(input_action):
			invoke(self)
	else:
		if event.is_action_pressed(input_action):
			invoke(self)
