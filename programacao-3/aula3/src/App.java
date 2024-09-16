public class App {
    public static void main(String[] args) throws Exception {
        Cachorro cachorro = new Cachorro();
        Macaco macaco = new Macaco();

        cachorro.movimentar();
        cachorro.fazerBarulho();

        macaco.movimentar();
        macaco.fazerBarulho();
    }
}
