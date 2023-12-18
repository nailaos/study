package ticket;

public class Ticket extends Thread {

    TicketPool myPool;
    int target;
    int myTicket;

    public Ticket(TicketPool tpl, int treq) {
        myPool = tpl;
        target = treq;
        myTicket = 0;
    }

    public void run() {
        synchronized (myPool) {
            int res = myPool.getRest();
            if (res >= target) {
                myPool.reduceRest(target);
                myTicket += target;
                target = 0;
            } else {
                myPool.reduceRest(res);
                myTicket = res;
                target -= res;
            }
        }
    }

    public int getObtained() {
        return myTicket;
    }
}