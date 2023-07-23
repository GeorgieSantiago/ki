extends Cue

@export var enabled: bool

func _physics_process(delta):
	if enabled:
		invoke(delta)
