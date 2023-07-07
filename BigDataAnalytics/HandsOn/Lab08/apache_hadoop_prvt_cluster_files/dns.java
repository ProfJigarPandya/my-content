import java.net.InetAddress;
import java.net.UnknownHostException;

public class dns {

  public static void main(String[] args) throws UnknownHostException {
    InetAddress addr = InetAddress.getLocalHost();

    System.out.println(
      String.format(
        "IP:%s hostname:%s canonicalName:%s",
        addr.getHostAddress(),       // The "default" IP address
        addr.getHostName(),          // The hostname (from gethostname())
        addr.getCanonicalHostName()  // The canonicalized hostname (from resolver)
      )
    );
  }

}
