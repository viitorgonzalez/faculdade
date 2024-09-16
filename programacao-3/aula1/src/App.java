public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("APP");

        // Objeto 1 e 2
        Veiculo veiculo = new Veiculo();
        Roda roda = new Roda();

        roda.setMarca("Chevrolet");
        roda.setModelo("BSS");

        System.out.println(veiculo.getMarca()); // null
        
        System.out.println(roda.getModelo());
        System.out.println(roda.getMarca());

        // Objeto 3 e 4
        Pessoa pessoa = new Pessoa();
        Profissao profissao = new Profissao();

        profissao.setNome("Vítor Gonzalez");
        profissao.setCargo("Estagiário");

        System.out.println(pessoa.getNome()); // null

        System.out.println(profissao.getCargo());
        System.out.println(profissao.getNome());
    }
}
