public class Computer extends Product {
    private String cpu;
    private String ram;
    private String storage;
    private String cooler;
    private String psu;
    private String caseName;

    public Computer(int code,String description, int price, String cpu, String ram,
        String storage, String cooler, String psu, String caseName) {
        super(code, description, price);
        this.cpu = cpu;
        this.ram = ram;
        this.storage = storage;
        this.cooler = cooler;
        this.psu = psu;
        this.caseName = caseName;
    }

    public String getCpu() {
        return this.cpu;
    }

    public String getRam() {
        return this.ram;
    }

    public String getStorage() {
        return this.storage;
    }

    public String getCooler() {
        return this.cooler;
    }

    public String getPsu() {
        return this.psu;
    }

    public String caseName() {
        return this.caseName;
    }
}