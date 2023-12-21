plugins {
    application
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

application {
    mainClass.set("emiyasyahriel.ktpnik.KtpNikSample")
} 

dependencies {
    implementation(project(mapOf("path" to ":ktpnik")))
}