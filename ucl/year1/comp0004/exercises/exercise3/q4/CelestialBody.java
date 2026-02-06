package year1.comp0004.exercises.exercise3.q4;

import java.util.ArrayList;
import java.util.Iterator;

public class CelestialBody {

    private CelestialBody bodyOrbited;

    private double combinedMass;

    private double mass;

    private double radiusFromParent;

    private String name;

    private ArrayList<CelestialBody> bodiesInOrbit;

    public CelestialBody() {
        this("", 0.0);
    }

    public CelestialBody(String name) {
        this(name, 0.0);
    }

    public CelestialBody(String name, double mass) {
        this.bodyOrbited = null;
        this.radiusFromParent = 0.0;
        this.name = name;
        this.mass = mass;
        this.combinedMass = mass;
        this.bodiesInOrbit = new ArrayList<>();
    }

    private void setBodyOrbited(CelestialBody bodyOrbited) {
        this.bodyOrbited = bodyOrbited;
    }

    public void setRadiusFromParent(double radius) {
        this.radiusFromParent = radius;
    }
    
    public void addToOrbit(CelestialBody newOrbiter, double radius) {
        this.bodiesInOrbit.add(newOrbiter);
        this.combinedMass += newOrbiter.mass;
        newOrbiter.setBodyOrbited(this);
        newOrbiter.setRadiusFromParent(radius);
    }
    
    public void removeFromOrbit(CelestialBody c) {
        this.bodiesInOrbit.remove(c);
        this.combinedMass -= c.getMass();
        c.setBodyOrbited(null);
        c.setRadiusFromParent(0.0);
    }
    
    public CelestialBody getBodyOrbited() {
        return this.bodyOrbited;
    }

    public double getRadiusFromParent() {
        return this.radiusFromParent;
    }

    public double getMass() {
        return this.mass;
    }

    public double getCombinedMass() {
        return this.combinedMass;
    }

    @Override
    public String toString() {
        String result = "Name: ";
        result += this.name + ", Mass: ";
        result += this.getMass() + ", Orbiters: ";
        result += this.bodiesInOrbit.toString();

        return result;
    }

    public Iterator<CelestialBody> bodies() {
        return this.bodiesInOrbit.iterator();
    }

}