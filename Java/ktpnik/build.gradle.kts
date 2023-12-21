plugins {
    `java-library`
}

sourceSets {                                
    main {                                  
        java.srcDir("main/src")
    }
}

java {                                      
    sourceCompatibility = JavaVersion.VERSION_11
    targetCompatibility = JavaVersion.VERSION_11
}