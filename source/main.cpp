#include <iostream>
#include <memory>

#include "completions.h"
#include "models.h"
#include "request.h"
#include "response.h"

int main(int argc, char *argv[]) {
  std::shared_ptr<OpenAI::Request> req =
      std::make_shared<OpenAI::Request>(OpenAI::Authorization{"api-key"});
  /*OpenAI::Model model{req};
  OpenAI::Response r = model.list();
  std::cout <<r.status_code()<< " "<< r.data()<<std::endl;
  r = model.retrive( "text-babbage:001");
  std::cout <<r.status_code()<< " "<< r.data();
  */
  OpenAI::Completions comp{req};
  OpenAI::Completions::Options opts;
  opts.prompt = "tell a joke";
  opts.max_tokens = 100;
  OpenAI::Response r = comp.create("text-davinci-003", opts);
  std::cout << r.status_code() << " " << r.data() << std::endl;
  return 0;
}
