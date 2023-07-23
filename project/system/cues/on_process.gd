extends Cue

@export var enabled: bool

func _process(delta):
	if enabled:
		invoke(delta)
