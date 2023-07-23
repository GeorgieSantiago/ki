extends Cue

@export var delay: int = 1
@export var is_one_shot: bool = true
var timer: Timer

func _ready():
	timer = Timer.new()
	timer.wait_time = delay
	timer.autostart = true
	timer.one_shot = is_one_shot
	timer.connect("timeout", _callback)
	add_child(timer)
	
func _callback():
	invoke(self)
