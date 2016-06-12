class Rover:
    def __init__(self, dir, x = 0, y = 0):
        self.x_ = x
        self.y_ = y
        self.direction_ = Direction.translate(dir)

    def getLocation(self):
        return (self.x_, self.y_)
    
    def move(self, directive):
        for dir in directive:
            if dir in 'LR':
                self._turn(dir)
            if dir == 'M':
                self._moveForward()
        return (self.x_, self.y_)

    def _turn(self, dire):
        if dire == 'R': self._turnRight()
        if dire == 'L': self._turnLeft()
    
    def _turnLeft(self):
        self.direction_ = Direction.turnLeft(self.direction_)
        
    def _turnRight(self):
        self.direction_ = Direction.turnRight(self.direction_)
    
    def _moveForward(self):
        delta = Direction.nextStep(self.direction_)
        ( self.x_, self.y_) = ( delta[0] + self.x_, delta[1] + self.y_)

class Direction:
    NORTH = 0
    EAST = 1
    SOUTH = 2
    WEST = 3
    
    @classmethod
    def translate(cls, letter):
        if letter == 'N': return cls.NORTH
        if letter == 'E': return cls.EAST
        if letter == 'S': return cls.SOUTH
        if letter == 'W': return cls.WEST

    @classmethod
    def nextStep(cls, direction):
        delta = (0, 0)
        if direction == cls.NORTH:  delta = (0, 1)
        elif direction == cls.EAST: delta = (1, 0)
        elif direction == cls.SOUTH: delta = (0, -1)
        elif direction == cls.WEST: delta = (-1, 0)
                
        return delta
        
    @staticmethod
    def turnRight(direction):
        return ((direction + 1) % 4)
    @staticmethod
    def turnLeft(direction):
        return ((direction - 1) % 4)
    
'''
class Planet():
    def __init__(self, limitX, limitY):
        self.lx = limitX
        self.ly = limitY
        
    def isOutofRange(self, coor):
        return coor.x_ >= self.lx or coor.y_ > self.ly   
'''
    