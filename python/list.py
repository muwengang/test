#!/usr/bin/python

def compare(i,j):
	if(i.data > j.data):
		return True

class Node(object):
	def __init__(self):
		self.data = None
		self._prev = None
		self._next = None

class List(object):
	def __init__(self):
		self.head = None
		self._first = None
		self._last = None
	
	def isempty(self):
		return self.head == None

	def isfull(self):
		return False
	
	def moveToEnd(self):
		node = self.head
		while(node._next != None):
			node = node._next
		return node
	
	def append(self, data):
		node = Node()
		node.data = data
		if(self.head == None):
			self.head = node
			self._first = node
			self._last = node
		elif(self.head._next == None):
			self.head._next = node
			node._prev = self.head
			self._last = node	
		else:
			node._prev = self._last
			self._last._next = node
			self._last = node
	
	def find(self,data, func = None):
		if(self.head == None):
			return None
		else:
			node = self._first
			if(func == None):
				while(node != None):
					if(node.data == data):
						return node
					node = node._next
			else:
				while(node != None):
					if(func(node.data, data)):
						return node
					node = node._next
				
			return node
	
	def insert_behind(self,data,value):
		pos = self.find(data)
		if(pos == None):
			self.append(value)
		else:
			node = Node()
			node.data = value
			node._prev = pos
			node._next = pos._next
			pos._next._prev = node
			pos._next = node

	def insert_front(self,data,value):
		pos = self.find(data)
		if(pos == None):
			self.append(value)
		else:
			node = Node()
			node.data = value
			node._prev = pos._prev
			node._next = pos._prev._next
			pos._prev._next = node
			pos._prev = node

	def delete(self,data):
		pos = self.find(data)
		if(pos == self.head):
			self._first = self.head._next
			self.head = self.head._next
			self.head._prev = None
		elif(pos == self._last):
			self._last = self._last._prev
			self._last._next = None
		else:
			pos._prev._next =  pos._next
			pos._next._prev = pos._prev
			pos._next = None
			pos._prev = None
	
	def count(self):
		count = 0
		if(None == self.isempty()):
			return count
		else:
			node = self._first
			while (node != None):
				node = node._next
				count += 1
			return count
	def getItem(self, func = None):
		if(False == self.isempty()):
			if(func == None):
				node = self._first
				while(node != self._last):
					print(node.data),
					node = node._next
				print(node.data)
				print('----------------')
			else:
				node = self._first
				while(node != self._last):
					func(node.data)
					node = node._next
				func(node.data)
				print('----------------')
	def push(self,data):
		self.append(data)

	def pop(self,data):
		self._first = self.head._next
		self.head = self.head._next
		self.head._prev = None
		
	def sort(self, func = None):
		i = self.head;
		if func != None :
			while(i != None):
				j =  i._next
				while(j !=  None):
					if(compare(i,j)):
						data = i.data
						i.data = j.data
						j.data = data
					j = j._next
				i = i._next
		else:
			while(i != None):
				j =  i._next
				while(j !=  None):
					if(i.data > j.data):
						data = i.data
						i.data = j.data
						j.data = data
					j = j._next
				i = i._next
			
	def getItem_r(self, func = None):
		if(False == self.isempty()):
			if(func == None):
				node = self._last
				while(node != self._first):
					print(node.data),
					node = node._prev
				print(node.data)
				print('----------------')
			else:
				node = self._last
				while(node != self._first):
					func(node.data),
					node = node._prev
				func(node.data)
				print('----------------')

if __name__ == '__main__':
	list = List()
	list.append(3)
	list.append(4)
	list.append(8)
	list.append(5)
	list.append(6)
	list.insert_behind(8,9)
	list.getItem()
	list.insert_front(5,10)
	list.getItem()
	list.getItem_r()
	list.delete(10)
	list.getItem()
	list.getItem_r()
	list.delete(3)
	list.getItem()
	list.getItem_r()
	list.delete(6)
	list.getItem()
	list.getItem_r()
	print("count = %d" % list.count())
	list.sort(compare)
	list.getItem()
	list.getItem_r()
	
