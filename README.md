# Tokenizer

## About
This is a new project that I wanted to test myself through where I build a tokenizer program
inspired by my readings on GPT-2's tokenizer (hence why the data folder contains the encoder and vocab.bpe).

I wanted to understand a little more on the mechanics of [BPE](https://huggingface.co/learn/llm-course/en/chapter6/5), and so this project came about. It's not in any sense an attempt to replace BPE or anything like that, but more for me to learn some aspects of how things work under the hood.

To give myself a little more of a challenge, I decided to implement this in C++ which no doubt will take
me a little longer to get this project to a palatable state, but I figured I'd force myself to use 
C++ more for my personal projects.


## Current state

Right now, I've developed the core BPE merge loop on a simple word (e.g., lowest). This took surpsingly way longer to 
implement than I thought. So far, it's taken a couple of hours especially since I've restricted myself to use AI only when I get REALLY stuck on figuring out the proper algorithm. And to clarify, that doesn't mean to write any code for me. Just to give me hints if I get stuck on piece of logic. Using it more as a guide than having it do everything for me. The intention there is to force myself to think more algorithmatically and actually force my brain to understand the proper flow of the logic.

## Dev Env
- nvim (forcing myself to use it more - loving it!) 
- C++
- CMake
- Make
- Ubuntu
