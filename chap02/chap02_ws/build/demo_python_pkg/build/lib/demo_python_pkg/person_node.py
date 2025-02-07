import rclpy
from rclpy.node import Node

class PersonNode(Node):
    def __init__(self,node_name:str,name:str,age:int) -> None:
        super().__init__(node_name)
        #print("person 的__init__方法被调用了")
        self.age = age
        self.name = name

    def eat(self,food_name:str):
        #print(f'我叫{self.name}，今年{self.age}岁，我正在吃{food_name}')
        self.get_logger().info(f'我叫{self.name}，今年{self.age}岁，我正在吃{food_name}')

def main():
    rclpy.init()
    node = PersonNode('person_Node','张三',18)
    node.eat('鱼香肉丝')
    rclpy.spin(node)
    rclpy.shutdown()