#pragma once

#include <unordered_map>
#include <string>

#include "envoy/server/http_route_manager.h"

#include "common/router/rds_impl.h"

namespace Envoy {
namespace Server {

class HttpRouteManagerImpl : public HttpRouteManager {
public:
  HttpRouteManagerImpl() {}
  ~HttpRouteManagerImpl() {}

  // Server::HttpRouteManager
  std::vector<Router::RouteConfigProviderSharedPtr> routeConfigProviders() override;
  void addConfigProvider(const std::string& name,
                         std::weak_ptr<Router::RouteConfigProvider> routeConfigProvider) override;
  Router::RouteConfigProviderSharedPtr getConfigProvider(const std::string& name) override;
  void removeRouteConfigProvider(const std::string& name) override;

private:
  std::unordered_map<std::string, std::weak_ptr<Router::RouteConfigProvider>> route_config_providers_;
};
}
}