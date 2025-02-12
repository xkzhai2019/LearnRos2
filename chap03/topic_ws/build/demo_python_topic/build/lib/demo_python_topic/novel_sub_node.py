import rclpy
from rclpy.node import Node

from example_interfaces.msg import String
from queue import Queue
import time
import espeakng
import threading

class NovelSubNode(Node):
    def __init__(self,node_name):
        super().__init__(node_name)
        self.novels_queue_ = Queue() # 创建队列，存放小说
        self.novels_subscriber_ = self.create_subscription(String,'novel',self.novel_callback,10)
        self.speech_thread_ = threading.Thread(target=self.speak_thread)
        self.speech_thread_.start()
    
    def speak_thread(self):
        speaker = espeakng.Speaker()
        speaker.voice = 'zh'
        while rclpy.ok():
            if self.novels_queue_.qsize() > 0:
                text = self.novels_queue_.get()
                self.get_logger().info(f'正在朗读:{text}')
                speaker.say(text)
                speaker.wait()
            else:
                time.sleep(1)

    def novel_callback(self,msg):
        self.novels_queue_.put(msg.data)

def main(args=None):
    rclpy.init(args=args)
    node = NovelSubNode('novel_sub')
    rclpy.spin(node)
    rclpy.shutdown()