type Cat struct {
 alive int
}

func (c Cat) is_alive() bool {
 if c.alive==1{
 return true
 }
 return false
}

type Box struct {
}

func (b Box) open() Cat {
 cat := Cat{}
 cat.alive=rand.Int()%2
 return cat
}

