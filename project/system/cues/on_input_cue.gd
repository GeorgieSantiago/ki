extends Cue

@export var input_key: String
@export var on_released: bool

func _input(event):
	if on_released:
		if event.is_action_released(input_key):
			invoke(self)
	else:
		if event.is_action_pressed(input_key):
			invoke(self)
