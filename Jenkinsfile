pipeline {
    agent none
	environment {
        BITBUCKET_COMMON_CREDS = credentials('e74adb7e-a213-494f-b230-c49e0d5f3566')
    }

    stages {
        stage('Build') {
            agent { 
                label 'test_buildmachineshenxiumei'
				}
            
            steps {
                echo 'Building..'
				        checkout scm
			        	sh 'ls -l'
            }
        }
        stage('deploy') {
		        agent { 
				    node {
					    label 'test_buildmachineshenxiumei' 
					}
                	}
            steps {
                echo 'deploying..'
				sh 'mkdir test1111'
            }
        }
        stage('test') {
            steps {
                echo 'testing....'
				sh 'mkdir test1111'
            }
        }
    }
}
