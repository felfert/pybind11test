#import doesnotexist
import threading
import time
try:
    from pb11testcc import tprint
except ImportError:
    def tprint(str):
        print("py:{}".format(str))
    pass

class EmbedTest(object):
    def __init__(self, nthreads):
        self.done = True
        self.nthreads = nthreads
        self.threads = []
        tprint("EmbedTest init")

    def worker(self):
        it = 0
        while not self.done:
            it += 1
            tprint("  {} {}".format(threading.current_thread().name, it))
            time.sleep(0.1)

    def stop(self):
        tprint("stop()")
        self.done = True
        for thread in self.threads:
            thread.join()

    def start(self):
        tprint("start()")
        self.done = False
        threads = []
        for n in range(self.nthreads):
            thread = threading.Thread(name="worker{}".format(n), target=self.worker)
            thread.start()
            self.threads.append(thread)

if __name__ == "__main__":
    c = EmbedTest(10)
    c.start()
    time.sleep(10)
    c.stop()
