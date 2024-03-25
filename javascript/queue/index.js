
class Queue {
  constructor() {
    this.items = {};
    this.frontIndex = 0;
    this.backIndex = 0;
  }

  enqueue(item) {
    this.items[this.backIndex] = item;
    this.backIndex++;
    this.log(`Item ${this.valueToString(item)} inserted`);
  }

  dequeue() {
    const item = this.items[this.frontIndex];
    if (!item) return null;

    delete this.items[this.frontIndex];
    this.frontIndex++;
    this.log(`Item ${this.valueToString(item)} removed`);
    return item;
  }

  peek() {
    return this.items[this.frontIndex];
  }

  clear() {
    this.items = {};
    this.frontIndex = 0;
    this.backIndex = 0;
  }

  showQueue() {
    this.log(this.valueToString(this.items));
  }

  valueToString(value) {
    if (typeof (value) === 'object') {
      return JSON.stringify(value);
    }

    return String(value);
  }

  log(text) {
    console.log(text);
  }
}

const main = () => {
  const myQueue = new Queue();

  myQueue.enqueue(645);
  myQueue.enqueue(12564);
  myQueue.enqueue('foo');
  myQueue.enqueue('bar');
  myQueue.enqueue('test');
  myQueue.dequeue();
  myQueue.dequeue();
  myQueue.enqueue('Ohio');
  myQueue.dequeue();
  myQueue.dequeue();

  myQueue.showQueue();

  myQueue.enqueue('Miami');
  myQueue.dequeue();
  myQueue.dequeue();
  myQueue.enqueue('Maine');
  myQueue.dequeue();
  myQueue.dequeue();
  myQueue.dequeue();
  myQueue.enqueue('EUA');
  myQueue.enqueue('EQUADOR');
  myQueue.enqueue('BRAZIL');
  myQueue.enqueue('JAPAN');
  myQueue.enqueue('INDONESIA');

  myQueue.showQueue();

  myQueue.clear();

  myQueue.enqueue('EUA');
  myQueue.showQueue();
};

main();