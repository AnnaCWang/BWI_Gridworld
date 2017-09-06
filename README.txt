Gridworld

Requirements:

- Run on 64 bit Ubuntu 14.04 LTS Linux Machine

- Need to download UT building wide intelligence package located on github

	https://github.com/utexas-bwi/bwi



Code located in ‘agent’ src folder under MyAgent.cpp

Summary:

Given four agents localized on edges in their respective quadrants in a 2-dimensional grid, one must find the simplest, yet quickest way to make agents move over limited time events on specific points. Each time event appears based off of probability.

For each agent, I created a path with reaches every point before coming back to the start and repeating the process. Agent zero and one each covers a 5x6 grid and agent two and three each covers a 5x4 grid. This is using hamiltonian paths. Brute force method works best for this.