public class Cachorro implements Animal {
    @Override
    public void movimentar() {
        System.out.println("Cachorro andou...");
    }

    @Override
    public void fazerBarulho() {
        System.out.println("Au Au");
    }
}
