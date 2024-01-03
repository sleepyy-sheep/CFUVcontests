type Water struct {
	temp int
}

func NewWater(init_temp int) Water {
	return Water{init_temp}
}

type Teapot struct {
	temp int
}

func (t Teapot) is_boiling() bool {
	return t.temp >= 100
}
func (t *Teapot) heat_up(add_temp int) {
	t.temp += add_temp
}
func NewTeapot(water Water) Teapot {
	return Teapot(water)
}
