import unittest
from mars_rover import Rover


class TestRover(unittest.TestCase):
    def setUp(self):
        self.rover = Rover(x=1, y=1, dir='N')
        
    def testRoverLandingAtZero(self):
        rover = Rover('N')
        self.assertEqual((0, 0), rover.getLocation())
        
    def testRoverLandingOnPlanet(self):
        self.assertEqual((1, 1), self.rover.getLocation())
        
    def testRoverMoveForwardNorth(self):
        self.assertEqual((1, 2), self.rover.move('M'))
          
    def testRoverTurnRightMoveForwardEast(self):
        self.assertEqual((2, 1), self.rover.move('RM'))

    def testRoverTrunRightRightMoveForwardSouth(self):
        self.assertEqual((1, 0), self.rover.move('RRM'))
        
    def testRoverTrunRight3timesMoveForwardWest(self):
        self.assertEqual((0, 1), self.rover.move('RRRM'))

    def testRoverTrunRight4timesMoveForwardNorth(self):
        self.assertEqual((1, 2), self.rover.move('RRRRM'))

    def testRoverTurnLeftMoveForwardWest(self):
        self.assertEqual((0, 1), self.rover.move('LM'))

    def testRoverTurnLeftTwiceMoveForwardSouth(self):
        self.assertEqual((1, 0), self.rover.move('LLM'))

    def testRoverTurnLeft3TimesMoveForwardSouth(self):
        self.assertEqual((2, 1), self.rover.move('LLLM'))

    def testRoverTurnLeft4TimesMoveForwardNouth(self):
        self.assertEqual((1, 2), self.rover.move('LLLLM'))

    def testRoverAsExample1(self):
        rover1 = Rover('N', 1, 2)
        self.assertEqual((1, 3), rover1.move('LMLMLMLMM'))
        self.assertEqual((1, 4), rover1.move('M'))

    def testRoverAsExample2(self):
        rover1 = Rover('E', 3, 3)
        self.assertEqual((5, 1), rover1.move('MMRMMRMRRM'))
        self.assertEqual((6, 1), rover1.move('M'))

def suite():
    tests = unittest.defaultTestLoader.discover('./', "test_*.py")
    return unittest.TestSuite(tests)

if __name__ == '__main__':
    unittest.main(defaultTest = 'suite')